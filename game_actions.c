/**
 * @brief It implements the game update through user actions
 *
 * @file game_actions.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

/**
 * @brief It executes the unknown action
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 */
void game_actions_unknown(Game *game);

/**
 * @brief It executes the exit action
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 */
void game_actions_exit(Game *game);

/**
 * @brief It executes the next action
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 */
void game_actions_next(Game *game);

/**
 * @brief It executes the back action
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 */
void game_actions_back(Game *game);

/**
   Game actions implementation
*/

Status game_actions_update(Game *game, Command *command) {
  CommandCode cmd;

  /* Update of the last command */
  game_set_last_command(game, command);

  cmd = command_get_code(command);

  /* Switch to check the command */
  switch (cmd) {
    case UNKNOWN:
      game_actions_unknown(game);
      break;

    case EXIT:
      game_actions_exit(game);
      break;

    case NEXT:
      game_actions_next(game);
      break;

    case BACK:
      game_actions_back(game);
      break;

    default:
      break;
  }

  return OK;
}

/**
   Calls implementation for each action
*/

void game_actions_unknown(Game *game) {}

void game_actions_exit(Game *game) {}

void game_actions_next(Game *game) {
  /* Initialization of variables */
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  /* It gets the player location */
  space_id = game_get_player_location(game);
  
  /* Error control */
  if (space_id == NO_ID) {
    return;
  }

  /* It gets the south space */
  current_id = space_get_south(game_get_space(game, space_id));
  
  /* It sets the new location */
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return;
}

void game_actions_back(Game *game) {
  /* Initialization of variables */
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  /* It gets the player location */
  space_id = game_get_player_location(game);

  /* Error control */
  if (NO_ID == space_id) {
    return;
  }

  /* It gets the north space */
  current_id = space_get_north(game_get_space(game, space_id));
  
  /* It sets the new location */
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id);
  }

  return;
}