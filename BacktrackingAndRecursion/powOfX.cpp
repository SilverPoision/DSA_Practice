#include <iostream>

// recursive solution to calculate pow(x, n)
// using Divide & Conquer
// Hint: use divide and concur techniques on n where n can be even or odd

int power(int x, unsigned n)
{
  if (n == 0)
  {
    return 1;
  }
  int res = power(x, n / 2);

  if (n % 2 == 0)
  {
    return res * res;
  }
  else
  {
    return x * res * res;
  }
}

int main(void)
{
  int x = 2;
  unsigned n = 10;

  printf("pow(%d,%d) = %d", x, n, power(x, n));

  return 0;
}