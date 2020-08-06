#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*7.	Обчислити кількість тих елементів масиву, для яких викону¬ється нерівність am,n >3 та суму 
елементів менших, ніж 9*/
int SUMM(int **a, int n, int m )
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( a[i][j] < 9)
            {
                s+=a[i][j];
            }
        }
        
    }
    return s;
}
int COUNT(int **a, int n, int m)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if( a[i][j] > 3)
            {
                 counter++;
            }
        }
        
    }
    return counter;
}


int main (){
    int n,m;
    printf("Enter n ");
    scanf("%d",&n);
    printf("Enter m ");
    scanf("%d",&m);
    int **a;
    a = (int **)calloc(n,sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)calloc(m,sizeof(int));
    }

    for (int i = 0; i < n; i++,printf("\n"))
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand()%9+1;
            printf("%d ", a[i][j]);
        }
        
    }
printf("sum < 9 = %d\n count an,m > 3 = %d\n", SUMM(a,n,m), COUNT(a,n,m));
    system("pause");
    return 0;
}