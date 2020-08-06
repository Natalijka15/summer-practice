#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*В заданiй матрицi J(3,5) визначити найменший елемент серед непарних 
додатних елементiв, що розмiщуються в стовпчиках з непарними iндексами. Вивести вихiдну матрицю, найменший елемент 
та його iндекси.                                
*/
int main (){
int a[3][5], n =3, m = 5;
srand(time(NULL));
for (int i = 0; i < n; i++,printf("\n"))
{
    for (int j = 0; j < m; j++)
    {
        a[i][j] = rand()%9+1;
        printf("%d ", a[i][j]);
    }
    
}int min = a[0][0];
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if(a[i][j] > 0 && a[i][j]%2 !=0 )
        {
            if((j+1)%2 !=0)
            {
                min = (min > a[i][j])? a[i][j]: min;
            }
        }
    }
    
}
printf("\nmin = %d",min);
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if(a[i][j] > 0 && a[i][j]%2 != 0)
        {
            if(min == a[i][j])
            {
                printf("\n[%d][%d]",i+1,j+1);
            }
        }
    }
    
}

system("pause");
return 0;
}