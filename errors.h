/*
 * Sriram Balasubramaniam
 * Charm Patel
 * Karthik Shankar
 * Brian Stebar II 
 *
 * ECE 6102 - Spring 2014
 * Term Project - Distributed File System
 */

#ifndef ERRORS_H
#define ERRORS_H

#include <inttypes.h>


/* =========== *
 * ERROR CODES *
 * =========== */ 
#define NO_ERROR 0

#define ERR_BLOCK_NOT_DELETABLE 15
#define ERR_BLOCK_NOT_FOUND 2
#define ERR_BLOCK_NOT_NEW 6
#define ERR_BLOCK_SIZE_MISMATCH 7
#define ERR_FILE_BUSY 14
#define ERR_FILE_EXISTS 9
#define ERR_FILE_META_TYPE 10
#define ERR_FILE_NOT_FOUND 3
#define ERR_FOLDER_NOT_FOUND 4
#define ERR_HEADER_MISMATCH 5
#define ERR_INVALID_PATH 8
#define ERR_MEM_ALLOC 1
#define ERR_MSG_ACTION 11
#define ERR_MSG_RESOURCE 12
#define ERR_MSG_TYPE 13


/* ========================== *
 * ERROR EXPLANATION FUNCTION *
 * ========================== */ 
const char *error_message(uint8_t err_code);



#endif /* ERRORS_H */
