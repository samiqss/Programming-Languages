#include <stdio.h>
#include <limits.h>
#include <math.h>

int main()
{
   long L1 = LONG_MAX-1;
   double d = sqrt(L1);
   long L2 = d*d;
   printf("L1:%ld, d:%f, L2:%ld\n", L1, d, L2);
}

