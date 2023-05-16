#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileHandler.h"

#define MAX_LINE_LEN 1000
#define MAX_LEN 5000

char **file_get(char* path) { // returns entire content of the file
  char **data = malloc(MAX_LEN * sizeof(char *));
  FILE *fp;

  fp = fopen(path, "r");
  if(fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  int i = 0;
  while(!feof(fp) && !ferror(fp) && i < MAX_LEN) { // End of file or max length
    data[i] = malloc(MAX_LINE_LEN);

    if(fgets(data[i], MAX_LINE_LEN, fp) != NULL)
      i++;
  }

  fclose(fp);
  return data;
}

void file_append(char* path, char* data) { // Appends data to file
  FILE *fp;
  fp = fopen(path, "a"); // creates the file if it does not already exist

  if(fp == NULL) {
    printf("Error opening file.\n");
    return;
  }

  fprintf(fp, "%s", data);

  fclose(fp);
}

void file_remove(char *path, char* data) { // removes a line from the file
  const char *tmp_file ="database/tmp.txt";
  // TODO: Sort File?   
  FILE *fp, *fp_temp;
  fp = fopen(path, "r");
  fp_temp = fopen(tmp_file, "w");

  if(fp == NULL || fp_temp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  char *line = malloc(MAX_LINE_LEN);
  while(!feof(fp) && !ferror(fp)) {
    fgets(line, MAX_LINE_LEN, fp);

    if(strcmp(line, data) != 0) {
      fputs(line, fp_temp);
    }
  }
  free(line);
  fclose(fp);
  fclose(fp_temp);
  rename(tmp_file, path);
}

void file_delete(char *path) { // deletes the entire file
  if(remove(path) != 0) {
    printf("Failed to delete file %s", path);
  }
} 

