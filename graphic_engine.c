/**
 * @brief It implements a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"


#define WIDTH_MAP 48  /*!< The width of the map area */
#define WIDTH_DES 29  /*!< The width of the description area */
#define WIDTH_BAN 25  /*!< The width of the banner */
#define HEIGHT_MAP 13 /*!< The height of the map area */ 
#define HEIGHT_BAN 1  /*!< The height of the banner */
#define HEIGHT_HLP 2  /*!< The height of the help area */
#define HEIGHT_FDB 3  /*!< The height of the feedback area */

/**
 * @brief Graphic_Engine
 * 
 * This structs stores all the information of the graphic engine
 */
struct _Graphic_engine {
  Area *map, /*!< Map area, it shows the all the components of the map */
  *descript, /*!< Description of where is the object */
  *banner,   /*!< Title of the game */
  *help,     /*!< Help area, it shows the commands you can use */
  *feedback; /*!< Feedback area, its gives feedback depending on the command you use */
};

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  /* Error control */
  if (ge) {
    return ge;
  }

  screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 4, WIDTH_MAP + WIDTH_DES + 3);
  ge = (Graphic_engine *)calloc(1, sizeof(Graphic_engine));
  
  /* Error control */
  if (ge == NULL) {
    return NULL;
  }

  /* Initialization of an empty screen */
  ge->map = screen_area_init(1, 1, WIDTH_MAP, HEIGHT_MAP);
  ge->descript = screen_area_init(WIDTH_MAP + 2, 1, WIDTH_DES, HEIGHT_MAP);
  ge->banner = screen_area_init((int)((WIDTH_MAP + WIDTH_DES + 1 - WIDTH_BAN) / 2), HEIGHT_MAP + 2, WIDTH_BAN, HEIGHT_BAN);
  ge->help = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + 2, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_HLP);
  ge->feedback = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 3, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_FDB);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) {
  
  /* Error control */
  if (!ge) return;

  /* Destroyment of the actual screen */
  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  
  /* Initialization of variables of id, space, object, buffer and commands */
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Space *space_act = NULL;
  char obj = '\0';
  char str[255];
  CommandCode last_cmd = UNKNOWN;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* If the player is in a id of the space, it is created its actual id, the id at the north and the id at the south */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);

    /* If the object is in the north, or not, the object is assigned a value*/
    if (game_get_object_location(game) == id_back)
      obj = '+';
    else
      obj = ' ';

    /* If it exists the id of the north, the cage of the north id is created, including the number of id and object */
    if (id_back != NO_ID) {
      sprintf(str, "  |         %2d|", (int)id_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }
    
    /* If the object is in the id of the player, or not, the object is assigned a value*/
    if (game_get_object_location(game) == id_act)
      obj = '+';
    else
      obj = ' ';

    /* If it exists the id where the player is, the cage of the actual id is created, including the number of id, object and player */
    if (id_act != NO_ID) {
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  | ^C>     %2d|", (int)id_act);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }

    /* If the object is in the south, or not, the object is assigned a value*/
    if (game_get_object_location(game) == id_next)
      obj = '+';
    else
      obj = ' ';

    /* If it exists the id of the south, the cage of the south id is created, including the number of id and object */
    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|", (int)id_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "  |     %c     |", obj);
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  if ((obj_loc = game_get_object_location(game)) != NO_ID) {
    sprintf(str, "  Object location:%d", (int)obj_loc);
    screen_area_puts(ge->descript, str);
  }

  /* Paint in the banner area */
  screen_area_puts(ge->banner, " The haunted castle game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, exit or e");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = command_get_code(game_get_last_command(game));
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
