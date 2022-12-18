#include"hashtable.h"

#define Initial_Size 64

int hash(char* key);

HashTable hashtable_init() {
  HashTable hashtable;
  hashtable.files = malloc(64);
  hashtable.size = 0;

  return hashtable;
}

int hashtable_size(HashTable *hash_table) {
  return hash_table -> size;
}

bool hashtable_is_empty(HashTable *hash_table) {
  // non-existant hashtable is empty or if size is 0
  return hash_table == NULL || hash_table -> size == 0;
}

FILE* hashtable_get(HashTable* hash_table, char* key) {
  FILE *fp;
  int index = hash(key);

  if(index == -1) {
    return NULL;
  }

  return fp; // null pointer will be handled on call
}

int hash(char* key) {
  return -1;
}