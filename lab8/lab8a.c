#include <stdio.h>
#include <limits.h>

int main()
{
   int i1 = INT_MAX;
   long L = i1 * i1;
   int i2 =  L / i1;
   printf("i1:%d, L:%ld, i2:%d\n", i1, L, i2);
}

