#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*У частинi матрицi K(7,7),  розташованій під побічною діагоналлю і на ній, визначити максимальний і  мінімальний 
елементи з від'ємних елементів. Вивести вихiдну матрицю, максимальний і мінімальний елементи з від'ємних елементів 
та їх індекси.*/
int main() {
    int a[7][7], n = 7;
    srand(time(NULL));
    for (int i = 0; i < n; i++,printf("\n"))
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand()%18-9;
            printf("%d ", a[i][j]);
        }
    
    }int min = a[0][0], max = -10;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-i-1; j < n; j++)
        {
            if(a[i][j] < 0)
            {
                min = (min > a[i][j])? a[i][j]: min;
                max = (max < a[i][j])? a[i][j]: max;
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n-i-1; j < n; j++)
        {
            if(a[i][j] == min)
            {
                printf("\nmin[%d][%d] = %d",i+1,j+1,min);
            }else
                if(a[i][j] == max)
                {
                    printf("\nmax[%d][%d] = %d", i+1,j+1,max);
                }
        }
        
    }
    
    system("pause");
    return 0;
}