#include <stdio.h>
#include <limits.h>

#define true 1
#define false 0

int main()
{
   int a = 2, b = 4;
   if ((a && b) == true) printf("(%d && %d) is true\n", a, b);
   else if ((a && b) == false) printf("(%d && %d) is false\n", a, b);
   else if (a && b) printf("(%d && %d) is not false\n", a, b);
   else printf("(%d && %d) is %d\n", a, b, (a && b));

   if ((a & b) == true) printf("(%d & %d) is true\n", a, b);
   else if ((a & b) == false) printf("(%d & %d) is false\n", a, b);
   else if (a & b) printf("(%d & %d) is not false\n", a, b);
   else printf("(%d & %d) is %d\n", a, b, (a & b));

   if ((a || b) == true) printf("(%d || %d) is true\n", a, b);
   else if ((a || b) == false) printf("(%d || %d) is false\n", a, b);
   else if (a || b) printf("(%d || %d) is not false\n", a, b);
   else printf("(%d || %d) is %d\n", a, b, (a || b));

   if ((a | b) == true) printf("(%d | %d) is true\n", a, b);
   else if ((a | b) == false) printf("(%d | %d) is false\n", a, b);
   else if (a | b) printf("(%d | %d) is not false\n", a, b);
   else printf("(%d | %d) is %d\n", a, b, (a | b));

   a = 2, b = 3;
   if ((a && b) == true) printf("(%d && %d) is true\n", a, b);
   else if ((a && b) == false) printf("(%d && %d) is false\n", a, b);
   else if (a && b) printf("(%d && %d) is not false\n", a, b);
   else printf("(%d && %d) is %d\n", a, b, (a && b));

   if ((a & b) == true) printf("(%d & %d) is true\n", a, b);
   else if ((a & b) == false) printf("(%d & %d) is false\n", a, b);
   else if (a & b) printf("(%d & %d) is not false\n", a, b);
   else printf("(%d & %d) is %d\n", a, b, (a & b));

}

