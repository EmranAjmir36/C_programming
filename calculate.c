#include <stdio.h>
int main()
{

    int i, a, multiply;

    printf("Enter the number = ");
    scanf("%d", &a);

    for (i = 1; i <= 10; i++)
    {
        multiply = a * i;
        printf("%d * %d = %d \n", a, i, multiply);
    }

    return 0;
}