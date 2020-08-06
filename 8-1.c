#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*Написати функцію Leng, що знаходить довжину відрізка на площині за координатами його кінців:
За допомогою цієї функції знайти довжини відрізків AB, BC, CD, якщо їх координати задані. 
Вхідні дані:  А(0, 0), В(0, 4), С(3, 4), D(3, 0).
Вихідні дані: Довжина AB = 4, BC = 3, CD = 4.
*/
float Leng(int ax,int ay, int bx, int by)
{
    return sqrt(pow((bx-ax),2) + pow((by-ay),2));
}
int main (){
    int ax = 0, ay = 0, bx = 0,by = 4,cx = 3,cy = 4,dx = 3,dy = 0;
    printf("AB = %.2f,BC = %.2f CD = %.2f\n",Leng(ax,ay,bx,by),Leng(bx,by,cx,cy),Leng(cx,cy,dx,dy));
    system("pause");
    return 0;
}