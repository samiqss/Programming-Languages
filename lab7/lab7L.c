#include <stdio.h>
#include <limits.h>

enum vals { first=40, second='2', third };

int main()
{
   int i;
   for (i = 30; i < 80; i+=10)
      switch (i) {
         case first:  printf("first %c\n", i); break;
         case second: printf("second %c\n", i); break;
         case third:  printf("third %c\n", i); break;
         case 'F':    printf("F %c\n", i); break;
         default:     printf("none %c\n", i); break;
      }
}

