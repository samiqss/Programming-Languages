#include <stdio.h>
#include <limits.h>

int x = 1;

// add one to the contents of the specified memory location
void f(int *p)
{
   *p = *p + 1;
}

int main()
{
   const int *ptr = &x;
   f((int*)ptr);
   printf("const x(1): %d\n", x);
}

