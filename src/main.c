#include"hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool login();
bool authenticate(char *username, char *password);
bool decrypt_add(char *username, char *password);

int main() {
  while(!login()) { // keep showing login prompt until valid login given
    continue;
  }
  // char *key = "database/test.txt";
  // char *data = "test data";
  // // char *output;
  // HashTable h = hashtable_init();
  // hashtable_add(&h, key, data);
  // printf("%p\n", hashtable_get(&h, "a"));
  // hashtable_cleanup(&h);
  return 1;
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

  printf("Username: %s", user);
  printf("Password: %s", password);

  // if(authenticate(user, password)) {
  //   printf("User Authenticated!");
  //   decrypt_add();
  // } else {
  //   printf("Incorrect Username or Password");
  //   return false;
  // }
  return true;
}

void menu() {
}
