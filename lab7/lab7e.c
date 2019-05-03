#include <stdio.h>
#include <limits.h>

// add one to the contents of the specified memory location
void f(int *p)
{
   *p = (*p) + 1;
}

int main()
{
   const int x = 1;
   const int* ptr = &x;
   f((int*)(ptr));
   printf("const x(1): %d\n", x);
}

