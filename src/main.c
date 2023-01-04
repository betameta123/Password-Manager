#include"hashtable.h"
#include <stdio.h>

int main() {
  char *key = "database/test.txt";
  char *data = "test data";
  // char *output;
  HashTable h = hashtable_init(NULL);
  HashElement e = hashElement_init(key, data);
  HashElement e1 = hashElement_init("a", "a");
  HashElement e2 = hashElement_init("b", "b");
  HashElement e3 = hashElement_init("c", "c");
  HashElement e4 = hashElement_init("d", "d");
  HashElement e5 = hashElement_init("e", "e");
  HashElement e6 = hashElement_init("f", "f");
  HashElement e7 = hashElement_init("g", "g");
  h = hashtable_add(&h, &e);
  h = hashtable_add(&h, &e1);
  h = hashtable_add(&h, &e2);
  h = hashtable_add(&h, &e3);
  h = hashtable_add(&h, &e4);
  h = hashtable_add(&h, &e5);
  h = hashtable_add(&h, &e6);
  h = hashtable_add(&h, &e7);
  char *ptr = hashtable_get(&h, key);
  printf("%s", ptr);
  ptr = hashtable_get(&h, "a");
  printf("%s", ptr);
  ptr = hashtable_get(&h, "b");
  printf("%s", ptr);
  return 0;

}
