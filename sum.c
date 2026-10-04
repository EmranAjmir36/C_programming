#include <stdio.h>
int main()
{

    int sum = 0, n, i;

    printf("Enter the n = ");
    scanf("%d", &n);

    for (i = 1; i <= n; i = i + 1)
    {
        sum = sum + i;
    }
    printf(" Sum is %d", sum);
    return 0;
}