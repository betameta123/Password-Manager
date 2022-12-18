#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct HashTable {
  FILE **files;
  int size;
} HashTable;

HashTable hashtable_init();
int hashtable_size(HashTable *hash_table);
bool hashtable_is_empty(HashTable *hash_table);
FILE* hashtable_get(HashTable* hash_table, char* key);
void hashtable_add(HashTable *hash_table, char* key);
void hashtable_remove(HashTable *hash_table, char* key);
void hashtable_empty(HashTable *hash_table);
void hashtable_cleanup(HashTable *hash_table);
#endif
