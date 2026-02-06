/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "game.h"
#include "game_actions.h"
#include "graphic_engine.h"

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);

void game_loop_cleanup(Game game, Graphic_engine *gengine);

/**
 * @brief Main function of the game
 * @author Profesores PPROG
 * * @param argc The number of arguments
 * @param argv The arguments
 * @return 0 if everything goes well or 1 if there was some mistake
 */
int main(int argc, char *argv[]) {
  Game game;
  Graphic_engine *gengine;
  int result;
  Command *last_cmd;

  /* Error control */
  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  /* Initialization of the game and the engine */
  result = game_loop_init(&game, &gengine, argv[1]);

  /* Error control */
  if (result == 1) {
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  } else if (result == 2){
    fprintf(stderr, "Error while initializing graphic engine.\n");
    return 1;
  }

  /* It gets the last command */
  last_cmd = game_get_last_command(&game);

  /* Loop until the game finishes or the user exits */
  while ((command_get_code(last_cmd) != EXIT) && (game_get_finished(&game) == FALSE)) {
    graphic_engine_paint_game(gengine, &game);
    command_get_user_input(last_cmd);
    game_actions_update(&game, last_cmd);
  }

  game_loop_cleanup(game, gengine);

  return 0;
}

/**
 * @brief It initializes the game and the graphic engine
 * @author Profesores PPROG
 * * @param game a pointer to the game
 * @param gengine a double pointer to the graphic engine
 * @param file_name the name of the file
 * @return 0 if everything goes well or 1 if there was some mistake
 */
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name) {
  
  /* Error control */
  if (game_create_from_file(game, file_name) == ERROR) {
    return 1;
  }

  /* Error control */
  if ((*gengine = graphic_engine_create()) == NULL) {
    game_destroy(game);
    return 1;
  }

  return 0;
}

/**
 * @brief It cleans up the game and the graphic engine
 * @author Profesores PPROG
 * * @param game the game structure
 * @param gengine a pointer to the graphic engine
 */
void game_loop_cleanup(Game game, Graphic_engine *gengine) {
  game_destroy(&game);
  graphic_engine_destroy(gengine);
}