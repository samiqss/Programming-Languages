#include <stdio.h>
#include <limits.h>

enum bool { false, true };

int main()
{
   int a = 1, b = 2;
   enum bool result = (a > b)? true : false;
   printf("(%d>%d) is %d\n", a, b, result);
   result = (b > a)? true : false;
   printf("(%d>%d) is %d\n", b, a, result);
}

