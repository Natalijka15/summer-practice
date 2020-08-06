#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main (){
    double x,y;
    printf("x = ");
    scanf("%lf",&x);
    printf("y = ");
    scanf("%lf",&y);
    if((y >= 2*(x-2)) && (y <= 2) && (y>=0) && (y >= -1*2*(x+2)))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    
system("pause");
return 0;
}