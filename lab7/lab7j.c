#include <stdio.h>
#include <limits.h>

int main()
{
   int x = 5;
   int y = 3;
   int p = x - y;
   int n = y - x;
   if (p) {
      printf("%d is true\n", p);
   } else {
      printf("%d is false\n", p);
   }
   if (n) {
      printf("%d is true\n", n);
   } else {
      printf("%d is false\n", n);
   }
}

