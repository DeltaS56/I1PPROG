/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include "command.h"



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define CMD_LENGTH 30 /*!< The length of the command */

char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}}; /*!< List of commands, short and long */

/**
 * @brief Command
 *
 * This struct stores all the information related to a command.
 */
struct _Command {
  CommandCode code; /*!< Name of the command */
};

/** command_create allocates memory for a new space
 *  and initializes its members
 */
Command* command_create() {
  Command* newCommand = NULL;

  newCommand = (Command*)calloc(1,sizeof(Command));
  
  /* Error control */
  if (newCommand == NULL) {
    return NULL;
  }

  /* Initialization of an empty command*/
  newCommand->code = NO_CMD;

  return newCommand;
}

Status command_destroy(Command* command) {
  
  /* Error control */
  if (!command) {
    return ERROR;
  }

  free(command);
  command = NULL;
  return OK;
}

Status command_set_code(Command* command, CommandCode code) {
  
  /* Error control */
  if (!command) {
    return ERROR;
  }

  command->code=code;

  return OK;
}

CommandCode command_get_code(Command* command) {
  
  /* Error control */
  if (!command) {
    return NO_CMD;
  }
  return command->code;
}

Status command_get_user_input(Command* command) {
  
  /* Initialization of variables*/
  char input[CMD_LENGTH] = "", *token = NULL;
  int i = EXIT - NO_CMD;
  CommandCode cmd;

  /* Error control */
  if (!command) {
    return ERROR;
  }

  /* It reads the command and put it in another variable without spaces and new lines */
  if (fgets(input, CMD_LENGTH, stdin)) {
    token = strtok(input, " \n");
    /* Error control */
    if (!token) {
      return command_set_code(command, UNKNOWN);
    }
    
    /* Initialization of a variable */
    cmd = UNKNOWN;
    /* It creates a loop to see the commands and change its apointed number so they match, it does not matter if they are capital letter or not, or if they are short or long commands*/
    while (cmd == UNKNOWN && i < N_CMD) {
      if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL])) {
        cmd = i + NO_CMD;
      } else {
        i++;
      }
    }
    return command_set_code(command, cmd);
  }
  else
    return command_set_code(command, EXIT);
  
}
