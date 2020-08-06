#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Дано дійсну матрицю А розмірності nxm та координати двох її елементів. Визначити максимальне значення з вказаних 
чисел.
Вхідні дані: n = 3; m = 4; i1 = 1; j1 = 1; i2 = 2; j2 = 3; .
Вихідні дані: max = 3.
*/
int main (){
int n, m;
printf("Enter n ");
scanf("%d",&n);
printf("Enter m ");
scanf("%d",&m);
int a[n][m];
int ii[2], jj[2];
for (int i = 0; i < 2; i++)
{
    printf("Enter i%d ", i+1);
    scanf("%d",&ii[i]);
    ii[i] --;
    printf("Enter j%d ", i+1);
    scanf("%d",&jj[i]);
    jj[i]--;
}
for (int i = 0; i < n; i++,printf("\n"))
{
    for (int j = 0; j < m; j++)
    {
        a[i][j] = rand()%9+1;
        printf("%d ", a[i][j]);
    }
}int min, max = a[ii[0]][jj[0]];
min = max;
for (int i = 0; i < 2; i++)
{
    min = (min > a[ii[i]][jj[i]])? a[ii[i]][jj[i]]: min;
    max = (max < a[ii[i]][jj[i]])? a[ii[i]][jj[i]]: max;
}

printf("\nmin = %d\nmax = %d\n", min,max);
system("pause");
return 0;
}