#ifndef HASHTABLE_H
#define HASHTABLE_H

char **fileHandler_get(char* path); // returns entire content of the file
void file_append(char* path, char* data); // Appends data to file
void file_remove(char *path, char* data); // removes a line from the file
void file_create(char *path); // creates a new file
void file_delete(char *path); // deletes the entire file

#endif
