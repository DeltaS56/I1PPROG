/**
 * @brief It implements the game structure
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game.h"
#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
   Private functions
 */

/**
 * @brief Gets the id of the space in a defined position of the game
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param position the position in the array
 * @return the space id
 */
Id game_get_space_id_at(Game *game, int position);

/**
   Game interface implementation
*/

Status game_create(Game *game) {
  int i;

  /* Initialization of the spaces */
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  /* Initialization of game variables */
  game->n_spaces = 0;
  game->player_location = NO_ID;
  game->object_location = NO_ID;
  game->last_cmd = command_create();
  game->finished = FALSE;

  return OK;
}

Status game_create_from_file(Game *game, char *filename) {

  /* Error control */
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  /* Error control */
  if (game_load_spaces(game, filename) == ERROR) {
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

Status game_destroy(Game *game) {
  int i = 0;

  /* Destruction of the spaces */
  for (i = 0; i < game->n_spaces; i++) {
    space_destroy(game->spaces[i]);
  }

  command_destroy(game->last_cmd);

  return OK;
}

Space *game_get_space(Game *game, Id id) {
  int i = 0;

  /* Error control */
  if (id == NO_ID) {
    return NULL;
  }

  /* It searches the space with the id */
  for (i = 0; i < game->n_spaces; i++) {
    if (id == space_get_id(game->spaces[i])) {
      return game->spaces[i];
    }
  }

  return NULL;
}

Id game_get_player_location(Game *game) { return game->player_location; }

Status game_set_player_location(Game *game, Id id) {

  /* Error control */
  if (id == NO_ID) {
    return ERROR;
  }

  game->player_location = id;

  return OK;
}

Id game_get_object_location(Game *game) { return game->object_location; }

Status game_set_object_location(Game *game, Id id) {

  /* Error control */
  if (id == NO_ID) {
    return ERROR;
  }

  game->object_location = id;
  /* It sets the object in the space */
  space_set_object(game_get_space(game, id), TRUE);

  return OK;
}

Command *game_get_last_command(Game *game) { return game->last_cmd; }

Status game_set_last_command(Game *game, Command *command) {
  game->last_cmd = command;

  return OK;
}

Bool game_get_finished(Game *game) { return game->finished; }

Status game_set_finished(Game *game, Bool finished) {
  game->finished = finished;

  return OK;
}

void game_print(Game *game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  /* Print all the spaces */
  for (i = 0; i < game->n_spaces; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game->object_location);
  printf("=> Player location: %d\n", (int)game->player_location);
}

Id game_get_space_id_at(Game *game, int position) {

  /* Error control */
  if (position < 0 || position >= game->n_spaces) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Status game_add_space(Game *game, Space *space) {

  /* Error control */
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES)) {
    return ERROR;
  }

  /* Assignment of the new space */
  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}
