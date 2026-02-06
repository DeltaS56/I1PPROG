/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"

/**
 * @brief Graphic_engine data estrcuture
 */

typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief It creates a new screen, allocating memory and initializing its members
 * @author Profesores PPROG
 * 
 * @return A new graphic engine, initialized
 */

Graphic_engine *graphic_engine_create();

/**
 * @brief It destroys the new screen, freeing the allocated memory
 * @author Profesores PPROG
 * 
 * @param ge a pointer to the graphic engine
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It paints the map, including the player and the object, it also adds the banner, the help area and the feedback area
 * @author Profesores PPROG
 * 
 * @param ge a pointer to the graphic engine
 * @param game a pointer to the game structure
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
