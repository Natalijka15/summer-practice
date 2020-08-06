#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*
Обчислити та вивести середн∙ квадратичне елементiв масиву M(10), якi 
бiльше 5.                                                                
*/
int main (){
    int m[100];
    printf("Enter n ");
    int  n;
    scanf("%d", &n);
    int s = 0, counter = 0;
    float sz;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        m[i] = rand()%9+1;
        printf("%d ", m[i]);
        if( m[i] < 5)
        {
            s+=m[i];
            counter++;
        }
    }
    sz = s/2;
    s = 0;
    for (int i = 0; i < n; i++)
    {
        s+=pow((m[i]-sz),2);
    }
    float skv;
    skv = sqrt(s/counter);
    printf("\nskv = %.2f\n", skv);
    system("pause");
    return 0;
}