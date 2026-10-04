#include <stdio.h>
int main()
{

    int first, second, third;
    printf("Enter the first number = ");
    scanf("%d", &first);
    printf("Enter the second number = ");
    scanf("%d", &second);
    printf("Enter the third number = ");
    scanf("%d", &third);

    if (first > second)
    {
        printf("Largest = %d", first);
    }
    else if (second > third)
    {
        printf("Largest = %d", second);
    }
    else if (third > first)
    {
        printf("Largest = %d", third);
    }
    else
    {
        printf("Three numbers are same number");
    }

    return 0;
}