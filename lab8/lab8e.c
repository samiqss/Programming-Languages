#include <stdio.h>
#include <limits.h>

int f(int *x);
int g(int *x);

int main()
{
   int k = 10;
   int* p = &k;
   k = f(p) + g(p);
   printf("%d\n", k);
}

int f(int *x)
{
  *x = *x - 1;
  return *x;
}

int g(int *x)
{
  *x = *x * 10;
  return *x;
}

