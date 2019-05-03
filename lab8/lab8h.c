#include <stdio.h>
#include <limits.h>

int f(int x, int y);
int g(int *y);

int main()
{
   int x = 10;
   x = f(x++, g(&x));
   printf("result: %d\n", x);
}

int f(int x, int y)
{
   return x++ + ++y;
}

int g(int *y)
{
  return ++(*y);
}
