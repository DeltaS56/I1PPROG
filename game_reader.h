/**
 * @brief It defines the game reading functions
 *
 * @file game_reader.h
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "types.h"
#include "space.h"
#include "game.h"

/**
 * @brief reads the provided file and sets the spaces
 * @author Profesores PPROG
 *
 * @param Game pointer to the game
 * @param char pointer to the filename containing the data
 * @return
 */
Status game_load_spaces(Game *game, char *filename);

/**
 * @brief adds a space to the game
 * @author Profesores PPROG
 *
 * @param Game pointer to the game
 * @param Space pointer to the space
 * @return
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief gets position of a space in game
 * @author Profesores PPROG
 *
 * @param Game pointer to the game
 * @param int positional value
 * #return
 */
Id game_get_space_id_at(Game *game, int position);

#endif
