#include"hashtable.h"
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define INITIAL_SIZE 64

int hash_func(char* key);

HashElement hashElement_init(char* key) {
  char* dir;
  HashElement element;
  char *strpath;
  FILE* file;

  dir = key;
  element.key = key;
  //
  file = fopen(key, "wr");
  element.file = file;

  return element;
}

HashTable hashtable_init() {
  HashTable hashtable;
  hashtable.elements = calloc(INITIAL_SIZE, sizeof(HashElement));
  hashtable.size = 0;
  hashtable.length = INITIAL_SIZE;

  return hashtable;
}

int hashtable_size(HashTable *hash_table) {
  return hash_table->size;
}

bool hashtable_is_empty(HashTable *hash_table) {
  // non-existant hashtable is empty or if size is 0
  return hash_table == NULL || hash_table->size == 0;
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
    hash = (int)(hash_func(key) + pow(counter, 2)) % (hash_table->length);
    h = *((hash_table->elements) + hash);

    if(h == NULL) // if element does not exist
      return NULL;
    if(strcmp(key, h->key) == 0) // key found
      fp = h->file;
    else
      counter++; // next hash
  } while(strcmp(key, h->key) != 0);

  return fp;
}

bool hashtable_add(HashTable *hash_table, char* key, char* data) {
  int counter = 0, hash = 0;
  HashElement *hash_element;
  FILE *file;
  if(hash_table == NULL) // hash_table is empty create new hashtable
    *hash_table = hashtable_init();
  if(key == NULL)
    return false;

  // Change to shadow array implementation?
  if(hash_table->size == (int)((hash_table->length)/0.6f)) { // if hash_table is %60 full
    hash_table = realloc(hash_table, hash_table->length*2);
    hash_table->length = hash_table->length*2;
  }

  do {
    int hash = (int)(hash_func(key) + pow(counter, 2)) % (hash_table->length);
    hash_element = *(hash_table->elements + hash);
    if(hash_element == NULL) { // if empty node is found
      *hash_element = hashElement_init(key);
    }

  //   // Limit number of iterations to avoid inifinite loops 
  //   if(counter > hash_table->length * 2) 
  //     return false;
  //
  //   counter++;
  } while(hash_element != NULL);
  //
  // fprintf(hash_element->file, "%s", data);
  // fclose(hash_element->file);

  return true;
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
