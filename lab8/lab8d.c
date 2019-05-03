#include <stdio.h>
#include <limits.h>

int main()
{
   int x = 5;
   x++;
   ++x;
   int y = x++ + ++x;
   int z = y = x++;
//   z++ = y;
//   ++z = y;
     z++;
     z=y;
     ++z;
     z=y;
}

