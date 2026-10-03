#include <stdio.h>
int main()
{

    int change, coin = 0;

    printf("given cents = ");
    scanf("%d", &change);

    coin += change / 25;
    change = change % 25;

    coin += change / 10;
    change = change % 10;

    coin += change / 5;
    change = change % 5;

    coin += change / 1;
    change = change % 1;

    printf("coin is = %d", coin);
    return 0;
}