#include <stdio.h>
#include <limits.h>

int main()
{
   float f = 3.75;
   long L = (long)(f);
   printf("f as float: %g, L as long: %ld\n", f, L);
   printf("L as float: %g, f as long: %ld\n", L, f);
}

