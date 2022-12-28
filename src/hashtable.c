#include"hashtable.h"
#include<math.h>
#include<string.h>

#define INITIAL_SIZE 64

int hash_func(char* key);

HashTable hashtable_init() {
  HashTable hashtable;
  hashtable.elements = calloc(INITIAL_SIZE, sizeof(HashElement));
  hashtable.size = 0;
  hashtable.length = INITIAL_SIZE;

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
  FILE *fp = NULL;
  int counter = 0;
  int hash;
  HashElement *h;

  if(hash_table == NULL)
    return NULL; // null pointer will be handled on call
  do {
    // calculate hash
    hash = (int)(hash_func(key) + pow(counter, 2)) % (hash_table -> length);
    h = *((hash_table -> elements) + hash);

    if(h == NULL) // if element does not exist
      return NULL;
    if(strcmp(key, h -> key) == 0) // key found
      fp = h -> file;
    else
      counter++; // next hash
  } while(strcmp(key, h -> key) != 0);

  return fp;
}

void hashTable_add(HashTable *hash_table, char* key) {
}

int hash_func(char* key) { // polynomial rolling hash
  const int p = 31, m = pow(10, 9) + 9;
  unsigned long key_hash = 0;
  int p_pow = 0;

  while(*key != 0) {
    key_hash += (unsigned long)((*key) * pow((double)p, p_pow)) % m;
    key = key + 1;
  }
  return key_hash;
}
