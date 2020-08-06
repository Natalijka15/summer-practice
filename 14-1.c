#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]) {
  char S[256];
  int i = 0, big_letters = 0, digits = 0;

  printf("S=");
  fgets(S, 256, stdin);  

  for (; S[i]; i++) {
    if (isupper(S[i])) big_letters++;
    if (isdigit(S[i])) digits++;
  }

  printf("Big letters = %d, digits = %d", big_letters, digits);

  return 0;
}