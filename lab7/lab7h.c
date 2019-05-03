#include <stdio.h>
#include <limits.h>

void h(char *s);
void g(void *v) { h(v); }
void f(int *p) { g(p); }

int main()
{
   f((int*)("hi"));
}

void h(char *s)
{
   char c;
   int i = 0;
   while ((c = s[i++])) {
      printf("%c", c);
   }
   printf("\n");
}

