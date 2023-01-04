#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct HashElement {
  char *path;
  char *data;
} HashElement;

typedef struct HashTable {
  HashElement **elements;
  int size;
  int length;
  struct HashTable *shadow;
  int *shadow_counter;
} HashTable;

HashTable hashtable_init(HashTable* h);
HashElement hashElement_init(char *key, char *data);
int hashtable_size(HashTable *hash_table);
bool hashtable_is_empty(HashTable *hash_table);
char* hashtable_get(HashTable* hash_table, char* key);
HashTable hashtable_add(HashTable *hash_table, HashElement *e);
bool hashtable_remove(HashTable *hash_table, char* key);
void hashtable_empty(HashTable *hash_table);
void hashtable_cleanup(HashTable *hash_table);
#endif
