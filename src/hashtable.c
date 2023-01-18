#include"hashtable.h"
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define INITIAL_SIZE 1024

int hash_func(char* path, int length);

void hashElement_init(HashTable h) {
  for (int i = 0; i < h.length; i++) {
    *(h.elements + i) = calloc(1, sizeof(Element));
    (*(h.elements + i))->head = NULL;
    (*(h.elements + i))->tail = NULL;
    (*(h.elements + i))->size = 0;
  }
}

HashTable hashtable_init() {
  HashTable hash_table;
  hash_table.length = INITIAL_SIZE;
  hash_table.size = 0;
  hash_table.elements = calloc(hash_table.length, sizeof(HashElements));
  hashElement_init(hash_table);
  return hash_table;
}

int hashtable_size(HashTable *hash_table) {
  return hash_table->size;
}

bool hashtable_is_empty(HashTable *hash_table) {
  // non-existant hashtable is empty or if size is 0
  return hash_table == NULL || hash_table->size == 0;
}

char* hashtable_get(HashTable* hash_table, char* key) {
  if(hash_table == NULL || key == NULL)
    return NULL;
  HashElements **elements = hash_table->elements;
  int length = hash_table->length;
  int hash = hash_func(key, length);

  Element *root = (*(elements + hash))->head;
  while (root != NULL && strcmp(root->key, key) != 0) {
    root = root->next; 
  }
  return root == NULL ? NULL : root->value;
}

bool hashtable_add(HashTable *hash_table, char *key, char *value) {
  if(key == NULL)
    return false;

  if(hash_table == NULL) {
    HashTable *h = calloc(1, sizeof(HashTable));
    *h = hashtable_init();
    hash_table = h;
  }

  HashElements **elements = hash_table->elements;
  int length = hash_table->length;
  int hash = hash_func(key, length);
  HashElements *root = (*(elements + hash));
  Element *iter = root->tail;
  //
  //
  Element *e = calloc(1, sizeof(Element));
  e->key = key;
  e->value = value;
  e->next = NULL;
  
  if(iter == NULL)
    root->head = e;
  else
    iter->next = e;

  root->tail = e;
  hash_table->size++;
  return true;
}

bool hashtable_remove(HashTable *hash_table, char *key) {
  if(key == NULL || hash_table == NULL)
    return false;

  HashElements **elements = hash_table->elements;
  int length = hash_table->length;
  int hash = hash_func(key, length);
  
  Element *root = (*(elements + hash))->head;
  Element *prev = NULL;

  if(root == NULL)
    return false;

  while(root != NULL && root->key != key) {
    prev = root;
    root = root->next;
  }

  if(root == NULL)
    return false;

  if(prev == NULL) { // if key is head
    (*(elements + hash))->head = root->next;
    return true;
  }

  prev->next = root->next;
  return true;
}

void hashtable_cleanup(HashTable *hash_table) {
  if(hash_table == NULL)
    return;

  for (int i = 0; i < hash_table->length; i++) { // Free all linked lists
    if(*(hash_table->elements + i) == NULL) {
      continue;
    }

    Element *e = (*(hash_table->elements + i))->head;
    Element *head = e;
    while(head != NULL) { // Iterate through all the elements to free every node
      e = e->next;
      free(head);
      head = e;
    }
    *(hash_table->elements + i) = NULL; // free the HashElements reference
  }
  hash_table = NULL;
}

int hash_func(char* key, int length) {
  int m = pow(10, 9) + 9;
  unsigned long path_hash = 0;

  while(*key != 0) {
    path_hash += (int)(*key) % m;
    key = key + 1;
  }
  return path_hash % length;
}

