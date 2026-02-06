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
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_load_spaces(Game *game, char *filename);
#endif
