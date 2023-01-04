#include"hashtable.h"
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define INITIAL_SIZE 4

int hash_func(char* path, int length, HashTable *hash_table);

HashElement hashElement_init(char* path, char* data) {
  HashElement element;
  element.data = data;
  element.path = path;

  return element;
}

HashTable hashtable_init(HashTable *h) {
  if(h == NULL) {
    h = calloc(1, sizeof(HashTable));
    h->elements = calloc(INITIAL_SIZE, sizeof(HashElement));
    h->size = 0;
    h->length = INITIAL_SIZE;
  } else {
    // free(h->shadow_counter);
  }
  h->shadow = calloc(1, sizeof(HashTable));
  h->shadow->elements = calloc(h->length * 2, sizeof(HashElement));
  h->shadow->size = h->size;
  h->shadow->length = h->length * 2;
  h->shadow_counter = calloc(1, sizeof(int));

  return *h;
}

int hashtable_size(HashTable *hash_table) {
  return hash_table->size;
}

bool hashtable_is_empty(HashTable *hash_table) {
  // non-existant hashtable is empty or if size is 0
  return hash_table == NULL || hash_table->size == 0;
}

char* hashtable_get(HashTable* hash_table, char* path) {
  int length = hash_table->length;
  HashElement **elements = hash_table->elements;

  int hash = hash_func(path, length, hash_table);
  printf("%i\n", hash);
  return (*(elements + hash))->data;
}

HashTable hashtable_add(HashTable *hash_table, HashElement *e) {
  char *path = e->path;
  HashElement **elements = hash_table->elements;
  int length = hash_table->length;
  HashElement **shadow_elements = hash_table->shadow->elements;
  int shadow_length = hash_table->shadow->length;

  if(hash_table == NULL || e == NULL)
    return *hash_table;

  if(hash_table->size > (int)(hash_table->length * 0.5)) {// switch to shadow
    HashTable *old_hash_table = hash_table;
    hash_table = malloc(sizeof(HashTable));
    *(hash_table) = *(old_hash_table->shadow);
    hash_table->shadow = malloc(sizeof(HashTable));
    // printf("%p\n", hash_table->shadow);
    *(hash_table->shadow) = hashtable_init(hash_table);
    length = hash_table->length;
    shadow_elements = hash_table->shadow->elements;
  }

  printf("%i ", hash_table->size);
  printf("%i ", length);
  int hash = hash_func(path, length, hash_table);
  *(elements + hash) = e; // overwrite if path already exists in hashtable
  hash = hash_func(path, shadow_length, hash_table->shadow);
  *(shadow_elements + hash) = e; // add new elements to shadow array
  *(hash_table->shadow->elements + *hash_table->shadow_counter) = *(hash_table->elements + *hash_table->shadow_counter);
  hash_table->shadow_counter++;
  hash_table->size++;
  hash_table->shadow->size++;
  return *hash_table;

}

void hashtable_cleanup(HashTable *hash_table) {
  free(hash_table);
}

int hash_func(char* path, int length, HashTable *hash_table) { // polynomial rolling hash
  const int p = 31, m = pow(10, 9) + 9;
  unsigned long path_hash = 0;
  int p_pow = 0;
  int counter = 0;

  while(*path != 0) {
    path_hash += (unsigned long)((*path) * pow((double)p, p_pow)) % m;
    path = path + 1;
  }

  do {
    path_hash = (long long)(path_hash + pow(counter, 2)) % length;
    counter++;
  } while(*(hash_table->elements + path_hash) != NULL &&
      strcmp((*(hash_table->elements + path_hash))->path, path) == 0 && 
      counter < 200);

return path_hash;
}

