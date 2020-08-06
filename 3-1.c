#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*В заданiй матрицi C(5,6) знайти середнє квадратичне значення. Вивести вихiдну матрицю та знайдене середнє 
квадратичне значення*/
double SKV(int **m,int row, int col)
{
    int s = 0;
    float sz;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            s+=m[i][j];
        }
    }
    sz =(float) s/2;
    s = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            s+=pow((m[i][j]-sz),2);
        }
    }
    return sqrt(s/(row * col));
}
int main (){
    // int a[100][100];
    int **a;
    
    int n,m;
    printf("Enter n ");
    scanf("%d",&n );
    printf("Enter m ");
    scanf("%d",&m);
    a = (int**)calloc(n,sizeof(int*));
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
    printf("skv = %.2lf \n", SKV(a,n,m));
system("pause");
return 0;
}