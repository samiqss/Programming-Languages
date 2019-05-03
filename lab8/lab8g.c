#include <stdio.h>
#include <limits.h>

int main()
{
   int i = ( 3 > 2 < 7);
   int j = ( 3 > 3 < 7);
   int k = ( 3 > 4 < 7);
   int l = ( 3 > 10 < 7);
   printf("%d,%d,%d,%d\n", i, j, k, l);
}

