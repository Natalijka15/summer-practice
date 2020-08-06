#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*7.	Скільки від’ємних та додатних значень має масив
*/
void Count(int *a, int n, int *pos, int *neg)
{
int pos_ = 0, neg_ = 0;
for (int i = 0; i < n; i++)
{
    
        if(a[i] > 0) pos_++;
        else if( a[i] < 0) neg_++; 
}
*pos = pos_;
*neg = neg_;
}

int main()
{
    int *a;
    printf("Enter n ");
    int n, neg_counter , pos_counter ;
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%20-10;
        printf("%d ", a[i]);
    }
    Count(a,n,&pos_counter,&neg_counter);
    printf("\npos = %d\nneg = %d\n", pos_counter, neg_counter);
    system("pause");
    return 0;
}