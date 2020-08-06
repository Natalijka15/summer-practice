#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>


int main(int argc, char *argv[]) {
  char full_name[75];
  size_t len, len_name = 0, i;

  setlocale(LC_ALL, 0);

  printf("Enter full name: ");
  fgets(full_name, 75, stdin);
  len = strlen(full_name);

  printf("Entered: %s\n", full_name);

  i = 0;
  while (full_name[i]) {
    if (full_name[i] == ' ') {
      len_name = ++i;
      while (full_name[i] != ' ') {
        full_name[i] = (char) toupper(full_name[i]);
        i++;
      }
      break;
    }
    i++;
  }

  printf("Len: %zu\n", len);
  printf("Len name : %zu\n", len_name);
  printf("New str: %s\n", full_name);

  system("pause");
  return 0;
}