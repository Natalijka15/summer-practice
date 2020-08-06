#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person {
  char surname[45];
  char address[65];
  char phone[10];
} TPerson;

void print_person(TPerson person);
void find_surname(TPerson *list, int n, char *surname);
void find_address(TPerson *list, int n, char *address);
void find_phone(TPerson *list, int n, char *phone);

int main(int argc, char *argv[]) {
  FILE *stream;
  TPerson *phone_list;
  int n, choice;
  char buf[256];

  stream = fopen("phonelist.txt", "rb");
  if (!stream) return 1;

  fread(&n, sizeof n, 1, stream);
  phone_list = malloc(n * (sizeof *phone_list));
  fread(phone_list, sizeof *phone_list, n, stream);
  fclose(stream);
  
  do {
    system("cls");
    printf("1. Пошук за пр?звищем.\n");
    printf("2. Пошук за адресою.\n");
    printf("3. Пошук за номером.\n");
    printf("4. Завершити програму.\n");
    printf("> ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: 
        printf("Введ?ть пр?звище: ");
        fflush(stdin);
        gets(buf);
        find_surname(phone_list, n, buf); 
        break;
      case 2:
        printf("Введ?ть адресу: ");
        fflush(stdin);
        gets(buf);
        find_address(phone_list, n, buf); 
        break;
      case 3:
        printf("Введ?ть номер телефону: ");
        fflush(stdin);
        gets(buf);
        find_phone(phone_list, n, buf); 
        break;
      case 4: return 0;
    }
    system("pause");
  } while (choice != 4);

  return 0;
}

void print_person(TPerson person) {
  printf("?м'я: %s\tАдреса: %s\tНомер: %s\n", person.surname,
    person.address, person.phone);
}

void find_surname(TPerson *list, int n, char *surname) {
  int i, find = -1;

  for (i = 0; i < n; i++)
    if (strncmp(list[i].surname, surname, strlen(surname)) == 0)
      find = i;

  if (find == -1) printf("Контакт з таким пр?звищем не знайдено.\n");
  else print_person(list[find]);
}

void find_address(TPerson *list, int n, char *address) {
  int i, find = -1;

  for (i = 0; i < n; i++)
    if (strncmp(list[i].address, address, strlen(address)) == 0)
      find = i;

  if (find == -1) printf("Контакт з такою адресою не знайдено.\n");
  else print_person(list[find]);
}

void find_phone(TPerson *list, int n, char *phone) {
  int i, find = -1;

  for (i = 0; i < n; i++)
    if (strncmp(list[i].phone, phone, strlen(phone)) == 0)
      find = i;

  if (find == -1) printf("Контакт з таким номером не знайдено.\n");
  else print_person(list[find]);
}