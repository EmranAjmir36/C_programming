#include <stdio.h>
int main()
{
    int height;

    do
    {
        printf("height = ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);

    for (int row = 1; row <= height; row++)
    {
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }
        for (int space = 1; space < 3; space = space + 1)
        {
            printf(" ");
        }
        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}