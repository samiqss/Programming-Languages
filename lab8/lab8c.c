#include <stdio.h>
#include <limits.h>

int main()
{
   int y, x = y=3, z=(printf("hi there\n"),-y);
   printf("x %d, y %d, z %d\n", x, y, z);
   int TheAnswer = printf("and life the universe and everything is.. ");
   printf("%d of course\n", TheAnswer);
}

