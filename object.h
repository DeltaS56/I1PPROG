#include "types.h"

typedef struct _Object Object;

/**
 * @brief It creates a new object, allocating memory and initializing its members
 *
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Object* object_create(Id id);

/**
 * @brief It destroys a object, freeing the allocated memory
 *
 * @param object a pointer to the object that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_destroy(Object* object);

/**
 * @brief It gets the id of a object
 *
 * @param object a pointer to the object
 * @return the id of object
 */
Id object_get_id(Object* object);

/**
 * @brief It sets the name of a object
 *
 * @param object a pointer to the object
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_name(Object* object, char* name);

/**
 * @brief It gets the name of a object
 *
 * @param object a pointer to the object
 * @return  a string with the name of the object
 */
const char* object_get_name(Object* object);

/**
 * @brief It prints the object information
 *
 * @param object a pointer to the object 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_print(Object* object);
