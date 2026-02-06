/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"

#define MAX_SPACES 100 /*!< Max number of spaces */

/**
 * @brief Game 
 */
typedef struct _Game {
  Id player_location;        /*!< Current id of the player */
  Id object_location;        /*!< Current id of the object */
  Space *spaces[MAX_SPACES]; /*!< Array of spaces */
  int n_spaces;              /*!< Current number of spaces */
  Command *last_cmd;         /*!< Last command entered */
  Bool finished;             /*!< Boolean to know if game is finished */
} Game;

/**
 * @brief It creates a new game, initializing its members
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_create(Game *game);

/**
 * @brief It creates a game loading it from a file
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param filename the name of the file
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_create_from_file(Game *game, char *filename);

/**
 * @brief It destroys the game, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_destroy(Game *game);

/**
 * @brief It gets the space structure from an id
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param id the id of the space
 * @return the space structure or NULL if error
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief It gets the player location
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return the id of the player location
 */
Id game_get_player_location(Game *game);

/**
 * @brief It sets the player location
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param id the new id for the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief It gets the object location
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return the id of the object location
 */
Id game_get_object_location(Game *game);

/**
 * @brief It sets the object location
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param id the new id for the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_object_location(Game *game, Id id);

/**
 * @brief It gets the last command
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return the last command structure
 */
Command* game_get_last_command(Game *game);

/**
 * @brief It sets the last command
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param command the new command
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief It gets if the game is finished
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return TRUE if finished, FALSE otherwise
 */
Bool game_get_finished(Game *game);

/**
 * @brief It sets the finished status
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param finished the new status
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief It prints the game information
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 */
void game_print(Game *game);

/**
 * @brief It adds a space to the game
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_space(Game *game, Space *space);

#endif
