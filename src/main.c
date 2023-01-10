#include"hashtable.h"
#include <stdio.h>

int main() {
  char *key = "database/test.txt";
  char *data = "test data";
  // char *output;
  HashTable h = hashtable_init();
  hashtable_add(&h, key, data);
  printf("%s\n", hashtable_get(&h, key));
  hashtable_cleanup(&h);
}
