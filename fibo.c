#include <stdio.h>
int main()
{

  int a = 0, b = 1, term, i, sum;

  printf("How many terms? = ");
  scanf("%d", &term);
  if (term == 1)
  {
    printf("0");
  }
  else if (term == 0)
  {
    printf("Hey user, you entered 0 terms, so there is nothing to display.");
  }
  else if (term >= 2)
  {
    printf("%d ", a);
    printf("%d ", b);
    for (i = 1; i <= (term - 2); i++)
    {
      sum = a + b;
      a = b;
      b = sum;
      printf("%d ", sum);
    }
  }
  else
  {
    printf("invalid-input message");
  }

  return 0;
}
