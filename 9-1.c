#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]) {
  int *a, n, i, j, sum;

  printf("n: ");
  scanf("%d", &n);
  a = malloc(n * (sizeof *a));
  if (!a) return 1;

  printf("Array:\n");
  srand(time(NULL));
  sum = 0;
  for (i = 0; i < n; i++) {
    a[i] = rand() % 6 - 2;
    sum += a[i];
    printf("%d\t", a[i]);
  }
  printf("\n");

  for (i = 0; i < n; i++) {
    if (a[i] < 0) {
      n++;
      a = realloc(a, n * (sizeof *a));
      if (!a) return 1;
      for (j = n - 1; j > i; j--)  {
        a[j] = a[j - 1];
      }
      a[i++] = sum;
    }
  }

  printf("New array:\n");
  for (i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");

  system("pause");
  return 0;
}