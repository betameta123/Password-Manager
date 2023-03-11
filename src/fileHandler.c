#include <stdio.h>
#include <stdlib.h>
#include "fileHandler.h"

#define MAX_LINE_LEN 1000
#define MAX_LEN 5000

char **file_get(char* path){ // returns entire content of the file
  char **data = malloc(sizeof(char*));
  FILE *fp;
  fp = fopen(path, "r");
  if(fp == NULL) {
    printf("Error opening file.\n");
    return NULL; // handle in frontend
  }

  int i = 0;
  while(!feof(fp) && !ferror(fp)) {
    data[i] = malloc(MAX_LINE_LEN);

    if(fgets(data[i], MAX_LINE_LEN, fp) != NULL)
      i++;
  }
  return data;
}

void file_append(char* path, char* data){ // Appends data to file
                                          
}

void file_remove(char *path, char* data){ // removes a line from the file
}

void file_create(char *path){ // creates a new file
}

void file_delete(char *path){ // deletes the entire file
}
