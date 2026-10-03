#include <stdio.h>
int main()
{

    int number, positive, negative, zero;

    printf("Enter the number = ");
    scanf("%d", &number);

    if (number > 0)
    {
        printf("Positive");
    }
    else if (number < 0)
    {
        printf("Negative");
    }
    else
    {
        printf("Zero");
    }

    return 0;
}