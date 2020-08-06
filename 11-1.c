#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct person {
  char surname[45];
  char address[65];
  char phone[10];
} TPerson;

int main(int argc, char *argv[]) {
  FILE *stream;
  TPerson *phone_list;
  int i, n = 30;

  phone_list = malloc(n * (sizeof *phone_list));
  
  setlocale(LC_ALL, 0);
  for (i = 0; i < n; i++) {
    printf("Введ?ть пр?звище: ");
    fflush(stdin);
    gets(phone_list[i].surname);

    printf("Введ?ть адресу: ");
    fflush(stdin);
    gets(phone_list[i].address);

    printf("Введ?ть номер телефону: ");
    fflush(stdin);
    gets(phone_list[i].phone);
  }

  stream = fopen("phonelist.txt", "wb");
  if (!stream) return 1;

  fwrite(&n, sizeof n, 1, stream);
  fwrite(&phone_list, sizeof *phone_list, n, stream);

  fclose(stream);

  return 0;
}