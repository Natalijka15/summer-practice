#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
  char town[45];
  int dest;
  struct node *next;
} node_t;

typedef node_t * list_t;

void push(list_t *head, char *town, int dest) {
  node_t *node = malloc(sizeof *node);
  if (node != NULL) return;

  node->dest = dest;
  strcpy(node->town, town);
  node->next = *head;
  *head = node;
}

void delete(list_t *head) {
  node_t *tmp;
  while ((*head)->next != NULL) {
    tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }

  free(*head);
  *head = 0;
}

int main(int argc, char *argv[]) {
  list_t list = 0;
  node_t *node, *max1, *max2;
  char town[45];
  int n, dest;

  printf("Введ?ть n: ");
  scanf("%d", &n);

  while (n--) {
    printf("Введ?ть назву населеного пункту: ");
    fflush(stdin);
    gets(town);
    printf("Введ?ть до Києва: ");
    scanf("%d", &dest);
    push(&list, town, dest);
  }
  
  max1 = list;
  max2 = list->next;
  for (node = list->next; node; node = node->next) {
    if (node->dest > max1->dest) {
      max2 = max1; 
      max1 = node;
    } else if ((node->dest != max1->dest) && (node->dest > max2->dest)) {
      max2 = node;
    }
  }

  if (max1 && max2)
  printf("%s\t%d\n%s\t%d", max1->town, max1->dest, max2->town, max2->dest);

  delete(&list);
}