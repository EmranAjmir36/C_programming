#include <stdio.h>
int main()
{

    int first, second;
    printf("Enter the first number = ");
    scanf("%d", &first);
    printf("Enter the second number = ");
    scanf("%d", &second);

    if (first > second)
    {
        printf("First number is greater");
    }
    else if (second > first)
    {
        printf("Second number is greater");
    }
    else
    {
        printf("Both are same number");
    }

    return 0;
}