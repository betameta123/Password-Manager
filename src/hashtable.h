#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct Element {
  char *key;
  char *value;
  struct Element *next;
} Element;

typedef struct HashElements {
  struct Element *head;
  struct Element *tail;
  int size;
} HashElements;

typedef struct HashTable {
  struct HashElements **elements;
  int length;
  int size;
} HashTable;


HashTable hashtable_init();
// HashElement hashElement_init(char *key, char *data);
bool hashtable_is_empty(HashTable *hash_table);
char* hashtable_get(HashTable* hash_table, char* key);
bool hashtable_add(HashTable *hash_table, char* key, char *value);
bool hashtable_remove(HashTable *hash_table, char* key);
void hashtable_empty(HashTable *hash_table);
void hashtable_cleanup(HashTable *hash_table);
#endif
