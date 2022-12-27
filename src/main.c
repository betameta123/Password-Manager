#include"hashtable.h"
#include <stdio.h>

int main() {
  char *key = "database/test.txt";
  char *data = "test data";
  char *output;
  HashTable h = hashtable_init();
  HashElement e;
  hashElement_init(key);
  hashtable_add(&h, key, data);
  // FILE *file = hashtable_get(&h, key);
  // fscanf(file, "%s", output);
  // printf("%s", output);

  return 0;

}
