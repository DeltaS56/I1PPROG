/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H


#define WORD_SIZE 1000 /*!< Word size for string arrays */
#define NO_ID -1 /*!< There is no Id */


/**
 * @brief Id data type
 */
typedef long Id; 

/**
 * @brief Bool data type
 */
typedef enum {
 FALSE, /*!< False value */
 TRUE  /*!< True value */
} Bool; 

/**
 * @brief Status data type
 */
typedef enum { 
 ERROR, /*!< Error value */
 OK     /*!< Ok value */
} Status; 

/**
 * @brief Direction data type
 */
typedef enum { 
 N, /*!< North direction */
 S, /*!< South directin */
 E, /*!< East direction */
 W  /*!< West direction */
} Direction; 

#endif
