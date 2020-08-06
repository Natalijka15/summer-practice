#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*7.	Дано масив цілих чисел a[i], і = 1, … , n. Використовуючи вказівники, знайти номера тих елементів масиву, 
які більші свого лівого сусіда, і кількість таких елементів. 
Вхідні дані: n = 6; a[i] = {31, 77, 2, 0, 12, 11}.
Вихідні дані: Номера елементів = 1, 4. Кількість = 2.
*/
int main() {
    int n;
    printf("Enter n");
    scanf("%d", &n);
    int *a,*p;
    a = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%20-10;
        printf("%d ", a[i]);
    } printf("\npoz = ");
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] < a[i+1])
        {
            printf("%d, ",i+2);
            counter++;
        }
    }
    printf("num of fig  = %d\n", counter);
        system("pause");
    return 0;
}