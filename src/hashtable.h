#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct HashElement {
  FILE *file;
  char *key;
} HashElement;

typedef struct HashTable {
  HashElement **elements;
  int size;
  int length;
} HashTable;

HashTable hashtable_init();
HashElement hashElement_init(char *key);
int hashtable_size(HashTable *hash_table);
bool hashtable_is_empty(HashTable *hash_table);
FILE* hashtable_get(HashTable* hash_table, char* key);
bool hashtable_add(HashTable *hash_table, char* key, char* data);
bool hashtable_remove(HashTable *hash_table, char* key);
void hashtable_empty(HashTable *hash_table);
void hashtable_cleanup(HashTable *hash_table);
#endif
