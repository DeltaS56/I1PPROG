/**
 * @brief It defines the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2 /*!< Columns, differents forms of writing a command */
#define N_CMD 5 /*!< Rows, number of commands */

/**
 * @brief CommandType data type
 */
typedef enum { 
 CMDS, /*!< Short command */
 CMDL  /*!< Long command */
} CommandType;

/**
 * @brief CommandCode data type
 */
typedef enum { 
 NO_CMD = -1, /*!< No command */
 UNKNOWN,     /*!< Command "unknown"*/
 EXIT,        /*!< Command "exit" */
 NEXT,        /*!< Command "next" */
 BACK         /*!< Command "back" */
} CommandCode;

/**
 * @brief Command data structure
 */
typedef struct _Command Command;

/**
 * @brief It creates a new command, allocating memory and initializing its members
 * @author Profesores PPROG
 * 
 * @return A new command, initialized
 */
Command* command_create();

/**
 * @brief It destroys the command, freeing the allocated memory
 * @author Profesores PPROG
 * 
 * @param command a pointer to the command structure
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_destroy(Command* command);

/**
 * @brief It sets the command
 * @author Profesores PPROG
 * 
 * @param command a pointer to the command
 * @param code which is the code that is going to be used
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_set_code(Command* command, CommandCode code);

/**
 * @brief It gets the command
 * @author Profesores PPROG
 * 
 * @param command a pointer to the command structure
 * @return the command
 */
CommandCode command_get_code(Command* command);

/**
 * @brief It checks if the command is correct, short or long
 * @author Profesores PPROG
 * 
 * @param command a pointer to the command structure
 * @return the function command_set_code, if all goes well the second argument is the command, if not it is exit
 */
Status command_get_user_input(Command* command);

#endif
