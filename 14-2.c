#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
  char fileName[45], *buff, *del = " ,.:;!?\n\r\t", str[256];
  FILE *file;
  int len = 100;

  printf("Enter name file: ");
  fgets(fileName, sizeof fileName, stdin);
  fileName[strlen(fileName) - 1] = 0;

  file = fopen(fileName, "rt");
  if (file == NULL) return 1;

  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  buff = (char *) malloc(size + 1);

  fseek(file, 0, SEEK_SET);
  size = fread(buff, 1, size, file);
  buff[size] = 0;

  fclose(file);

  char *word = strtok(buff, del);
  while (word != NULL) {
    int word_len = strlen(word);
    if (word_len % 2 != 0 && word_len < len) {
      len = word_len;
      strcpy(str, word);
    }
    word = strtok(NULL, del);
  }

  if (len != 100) {
    printf("len = %d\nstring = %s", len, str);
  }

  return 0;
}