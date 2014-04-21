/*
 * Sriram Balasubramaniam
 * Charm Patel
 * Karthik Shankar
 * Brian Stebar II 
 *
 * ECE 6102 - Spring 2014
 * Term Project - Distributed File System
 */

#ifndef MESSAGES_H
#define MESSAGES_H

#include "definitions.h"



/* ========= *
 * CONSTANTS *
 * ========= */
/* Message action definitions (REST-ful) */
#define GET 1
#define POST 2
#define PUT 3
#define DELETE 4

/* Message resource defintions */
#define BACS_BLOCK 3
#define BACS_FILE 1
#define BACS_FOLDER 2
#define BACS_SERVER 4

/* Message type definitions */
#define BACS_REQUEST 1
#define BACS_RESPONSE 2
#define BACS_ERROR 3


/* Message header size 
 *  - byte 0: Message action
 *  - byte 1: Message resource
 *  - byte 2: Message type
 */
#define BACS_HEADER_SIZE 3




/* ================= *
 * MESSAGE FUNCTIONS *
 * ================= */ 
 /* HEADER MANIPULATION */
void generate_header(uint8_t action, uint8_t resource, uint8_t type, char *msg);
uint8_t get_header_action(char *msg);
const char *get_header_action_string(uint8_t action);
uint8_t get_header_resource(char *msg);
const char *get_header_resource_string(uint8_t resource);
uint8_t get_header_type(char *msg);
const char *get_header_type_string(uint8_t resource);

 /* REQUESTS */
void create_msg_get_folder_meta_request(char *dirname, char **msg, 
                                        uint32_t *msg_len);
void create_msg_get_servers_request(char **msg, uint32_t *msg_len);
void create_msg_post_block_request(uuid_t uuid, uint32_t size, char *content,
                                   char **msg, uint32_t *msg_len);
void create_msg_post_file_request(char *filename, uint64_t file_size, 
                                  char **msg, uint32_t *msg_len);
void create_msg_post_folder_request(char *foldername, char **msg, 
                                    uint32_t *msg_len);
void parse_msg_get_folder_meta_request(char *msg, char **dirname);
void parse_msg_post_block_request(char *msg, uuid_t *uuid, uint32_t *size, 
                                  char **content);
void parse_msg_post_file_request(char *msg, char **filename, uint64_t *file_size);
void parse_msg_post_folder_request(char *msg, char **foldername);

/* RESPONSES */
void create_msg_get_folder_meta_response(meta_t *folder, char **msg, 
                                         uint32_t *msg_len);
void create_msg_get_servers_response(char **msg, uint32_t *msg_len);
void create_msg_post_block_response(uuid_t uuid, char **msg, uint32_t *msg_len);
void create_msg_post_file_response(meta_t *file, char **msg, uint32_t *msg_len);
void create_msg_post_folder_response(char **msg, uint32_t *msg_len);
void parse_msg_get_folder_meta_response(char *msg, basic_meta_t **metas, 
                                        uint32_t *num_metas);
void parse_msg_post_block_response(char *msg, uuid_t *uuid);
void parse_msg_post_file_response(char *msg, uuid_t **uuids, uint64_t *num_uuids);
void parse_msg_post_folder_response(char *msg);



/* ================ *
 * HELPER FUNCTIONS *
 * ================ */ 
void msg_with_single_element(uint8_t action, uint8_t resource, uint8_t type, 
                             void *element, uint32_t element_len, char **msg, 
                             uint32_t *msg_len);


/* =================== *
 * DEBUGGING FUNCTIONS *
 * =================== */ 
void print_msg(char *msg);

/* REQUESTS */
void print_msg_get_folder_meta_request(char *msg);
void print_msg_post_block_request(char *msg);
void print_msg_post_file_request(char *msg);
void print_msg_post_folder_request(char *msg);

/* RESPONSES */
void print_msg_get_folder_meta_response(char *msg);
void print_msg_post_block_response(char *msg);
void print_msg_post_file_response(char *msg);
void print_msg_post_folder_response(char *msg);

#endif /* MESSAGES_H */
