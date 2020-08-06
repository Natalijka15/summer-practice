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
    printf("1. ���� �� ��?���饬.\n");
    printf("2. ���� �� �����.\n");
    printf("3. ���� �� ����஬.\n");
    printf("4. ������� �ணࠬ�.\n");
    printf("> ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: 
        printf("����?�� ��?����: ");
        fflush(stdin);
        gets(buf);
        find_surname(phone_list, n, buf); 
        break;
      case 2:
        printf("����?�� �����: ");
        fflush(stdin);
        gets(buf);
        find_address(phone_list, n, buf); 
        break;
      case 3:
        printf("����?�� ����� ⥫�䮭�: ");
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
  printf("?�'�: %s\t����: %s\t�����: %s\n", person.surname,
    person.address, person.phone);
}

void find_surname(TPerson *list, int n, char *surname) {
  int i, find = -1;

  for (i = 0; i < n; i++)
    if (strncmp(list[i].surname, surname, strlen(surname)) == 0)
      find = i;

  if (find == -1) printf("���⠪� � ⠪�� ��?���饬 �� ��������.\n");
  else print_person(list[find]);
}

void find_address(TPerson *list, int n, char *address) {
  int i, find = -1;

  for (i = 0; i < n; i++)
    if (strncmp(list[i].address, address, strlen(address)) == 0)
      find = i;

  if (find == -1) printf("���⠪� � ⠪�� ����� �� ��������.\n");
  else print_person(list[find]);
}

void find_phone(TPerson *list, int n, char *phone) {
  int i, find = -1;

  for (i = 0; i < n; i++)
    if (strncmp(list[i].phone, phone, strlen(phone)) == 0)
      find = i;

  if (find == -1) printf("���⠪� � ⠪�� ����஬ �� ��������.\n");
  else print_person(list[find]);
}