/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Object
 *
 * This struct stores all the information of an object
 */
struct _Object {
  Id id;                    /*!< Identifier of the object */
  char name[WORD_SIZE + 1]; /*!< Name of the object */
};

Object* object_create(Id id) {
  Object* newObject = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newObject = (Object*)calloc(1, sizeof(Object));
  
  /* Error control */
  if (newObject == NULL) {
    return NULL;
  }

  /* Initialization of an empty object */
  newObject->id = id;
  newObject->name[0] = '\0';

  return newObject;
}

Status object_destroy(Object* object) {
  
  /* Error control */
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

Id object_get_id(Object* object) {
  
  /* Error control */
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

Status object_set_name(Object* object, char* name) {
  
  /* Error control */
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* object_get_name(Object* object) {
  
  /* Error control */
  if (!object) {
    return NULL;
  }
  return object->name;
}

Status object_print(Object* object) {
  
  /* Error control */
  if (!object) {
    return ERROR;
  }

  /* Print the object information */
  fprintf(stdout, "--> Object(Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}