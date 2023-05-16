#include"hashtable.h"
#include "fileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Testers
int run_testers();
int hashTable_tests();
int file_tests();

// Login
bool login();
bool authenticate(char *username, char *password);
bool decrypt_add(char *username, char *password);
void menu();

#define MAX_LINE_LEN 1000
#define MAX_LEN 5000
bool logged_in = false; 

int main() {
  while(!login()) { // keep showing login prompt until valid login given
    continue;
  }
  // while(1) {
  menu();
  // }

  return run_testers();
}


bool login() {
  const int MAX_USER_LENGTH = 64;
  const int MAX_PASSWORD_LENGTH = 256; // long password
  char user[MAX_USER_LENGTH], password[MAX_PASSWORD_LENGTH];
  char overflow;
  
  memset(user, 0, MAX_USER_LENGTH);
  memset(password, 0, MAX_PASSWORD_LENGTH);

  if(*user != 0) {
    printf("Username had unexpected value");
  }
  printf("Username: ");
  if(fgets(user, MAX_USER_LENGTH, stdin) == NULL) {
    printf("Invalid Username");
    return false;
  }

  // deal with overflow
  if(user[strlen(user) - 1] != '\n')
    while((overflow = getchar()) != '\n') {}
  
  // unexpected stuff
  if(*password != 0) {
    printf("Password had unexpected value");
  }
  printf("Password: ");
  if(fgets(password, MAX_PASSWORD_LENGTH, stdin) == NULL) {
    printf("Invalid Password");
    return false;
  }
  // deal with overflow
  if(user[strlen(user) - 1] != '\n')
    while((overflow = getchar()) != '\n') {}

  // Debug echo
  // printf("Username: %s", user);
  // printf("Password: %s", password);

  if(authenticate(user, password)) {
    printf("User Authenticated!\n");
    // decrypt_add();
  } else {
    printf("Incorrect Username or Password");
    return false;
  }
  return true;
}

bool authenticate(char *username, char *password) {
  char *key = "database/user.txt";
  char **users = file_get(key);
  // TODO: Decide Reasonable format for the file
  // TODO: Implement binary search for the user
  return false;
}

void menu() {
  printf("A cool menu\n");
}

int run_testers() {
  return file_tests() && hashTable_tests();

}

int file_tests() {
  char *key = "database/test.txt";
  char **data = file_get(key);

  for (int i = 0; i < (int)sizeof(*data) / (int)sizeof(**data); i++) {
    printf("%s", data[i]);
  }

  printf("------------------------------------\n\n");

  file_append(key, "foo bar\n");

  data = file_get(key);

  for (int i = 0; i < (int)sizeof(*data) / (int)sizeof(**data); i++) {
    printf("%s", data[i]);
  }

  printf("------------------------------------\n\n");

  file_remove(key, "foo bar\n");
  data = file_get(key);

  for (int i = 0; i < (int)sizeof(*data) / (int)sizeof(**data); i++) {
    printf("%s", data[i]);
  }
  return 0;
}

int hashTable_tests() {
  char *key = "database/test.txt";
  char *key1 = "database/test1.txt";
  char *data = "test data";
  char *data1 = "Hello World";
  // char *output;
  HashTable h = hashtable_init();
  hashtable_add(&h, key, data);
  hashtable_add(&h, key1, data1);
  printf("%p\n", hashtable_get(&h, key));
  hashtable_remove(&h, key);
  printf("%p\n", hashtable_get(&h, key));
  printf("%p\n", hashtable_get(&h, key1));
  hashtable_cleanup(&h);
  return 0; 
}
