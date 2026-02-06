/**
 * @brief It implements the player module
 *
 * @file player.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"

/**
 * @brief Player
 *
 * This struct stores all the information of a player
 */
struct _Player{
    Id id;                      /*!< Identifier of the player */
    char name[WORD_SIZE+1];     /*!< Name of the player */
    Id location;                /*!< Location of the player */
    Id object;                  /*!< Object carried by the player */
};

Player* player_create(Id id) {

    Player* newPlayer = NULL;

    /* Error control */
    if(id == NO_ID) return NULL;

    newPlayer = (Player*)calloc(1, sizeof(Player));
    
    /* Error control */
    if(newPlayer == NULL) {
        return NULL;
    }

    /* Initialization of an empty player */
    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->location = NO_ID;
    newPlayer->object = NO_ID;

    return newPlayer;
}

Status player_destroy(Player* player) {
    
    /* Error control */
    if(player == NULL) {
        return ERROR;
    }

    free(player);
    player = NULL;

    return OK;
}

Id player_get_id(Player* player) {

    /* Error control */
    if(player == NULL) {
        return NO_ID;
    }

    return player->id;
}

Status player_set_name(Player* player, char* name) {
    
    /* Error control */
    if(player == NULL || name == NULL) {
        return ERROR;
    }

    if(!strcpy(player->name, name)) {
        return ERROR;
    }

    return OK;
}

const char* player_get_name(Player* player) {

    /* Error control */
    if(player == NULL) {
        return NULL;
    }

    return player->name;
}

Status player_set_location(Player* player, Id location){

    /* Error control */
    if(player == NULL || location == NO_ID) {
        return ERROR;
    }

    player->location = location;

    return OK;
}

Id player_get_location(Player* player) {

    /* Error control */
    if(player == NULL) {
        return NO_ID;
    }

    return player->location;
}

Status player_set_object(Player* player, Id object) {

    /* Error control */
    if(player == NULL || object == NO_ID) {
        return ERROR;
    }

    player->object = object;

    return OK;
}

Id player_get_object(Player* player) {

    /* Error control */
    if(player == NULL) {
        return NO_ID;
    }

    return player->object;
}

Status player_print(Player *player) {

    /* Error control */
    if(player == NULL) {
        return ERROR;
    }

    /* Print the player information */
    fprintf(stdout,"--> Player(Id: %ld; Name: %s; Location: %ld; Object: %ld)\n", player->id, player->name, player->location, player->object);

    return OK;
}