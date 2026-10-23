#include <stdio.h>
int main()
{

    int number, i, isprime = 1;

    printf("Enter the number = ");
    scanf("%d", &number);

    if (number < 2)
    {
        isprime = 0;
    }

    for (i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            isprime = 0;
        }
    }

    if (isprime == 1)
    {
        printf("%d is prime.", number);
    }
    else
    {
        printf("%d is not prime.", number);
    }
    return 0;
}