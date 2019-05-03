#include <stdio.h>
#include <limits.h>

struct S {
   long L;
   struct S*   ptr;
   char str[10];
};

int main()
{
  struct S s1 = { 10, NULL, "hi" };
  struct S s2 = s1;
  printf("%ld, %p, %s\n", s2.L, s2.ptr, s2.str);
  s2.ptr = &s1;
  s2.str[0]= 'x';
  printf("%s\n", s2.str);
  printf("%s\n", s1.str);
}

