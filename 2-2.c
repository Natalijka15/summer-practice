#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*7.	Відсортувати елементи заданого масиву L(10) за спаданням та зменшити кожний елемент на мінімальний елемент.
Вивести  початковий та перетворений масиви та мінімальний елемент.
*/
int MIN__(int *a, int n)
{
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        min = (min > a[i])? a[i]:min;
    }
    return min;
}
int main (){
    int l[100];
    int n;
    printf("Enter n ");
    scanf("%d",&n);
    srand(time(NULL));
    printf("input array:\n");
    for (int i = 0; i < n; i++)
    {
        l[i] = rand()%9+1;
        printf("%d ", l[i]);
    }
    int min;
    min = MIN__(l,n);
   printf("\noutput array\n");
   for (int i = n-1; i >0; i--)
   {
       for (int j = 0; j < i; j++)
       {
           if(l[j] < l[j+1])
           {
               int tmp;
               tmp = l[j];
               l[j] = l[j+1];
               l[j+1] = tmp;
           }
       }
   }
   
for (int i = 0; i < n; i++)
{
    printf("%d ", l[i]-min);
}

    
system("pause");
return 0;
}