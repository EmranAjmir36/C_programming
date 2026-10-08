#include <stdio.h>
int main()
{

    int first, second, third;
    printf("Enter the first numbers = ");
    scanf("%d%d%d", &first, &second, &third);

    if (first > second && first > third)
    {
        printf("Largest = %d", first);
    }
    else if (second > third && second > first)
    {
        printf("Largest = %d", second);
    }
    else if (third > first && third > second)
    {
        printf("Largest = %d", third);
    }
    else if (first == second)
    {
        printf("First and second numbers are same");
    }
    else if (second == third)
    {
        printf("second and third numbers are same");
    }
    else if (first == third)
    {
        printf("first and third numbers are same");
    }
    else
    {
        printf("Three numbers are same number");
    }

    return 0;
}