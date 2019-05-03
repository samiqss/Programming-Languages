#include <stdarg.h>
#include <stdio.h>

// float sum(int numArgs, ...)
// ----------------------------
// returns the sum of all the arguments,
//    0 if no arguments are passed,
//    treats all arguments as floats

float sum(int numArgs, ...);

int main()
{
   float a=1, b=20.4, c=100.01;
   float tot0 = sum(0);
   float tot1 = sum(1, a);
   float tot2 = sum(2, a, b);
   float tot3 = sum(3, a, b, c);
   printf("%g, %g, %g, %g\n", tot0, tot1, tot2, tot3);
   return 0;
}

float sum(int numArgs, ...)
{
    // initialize the argument list
    va_list argList;
    va_start(argList, numArgs);

    float sum=0;

    
    // get ach value from the argument list,
    //     again treating them as float

    for (int i = 0; i < numArgs; i++) {
              float n = va_arg(argList, double);
              sum += n;
	   }

    // dispose of the argument list
    va_end(argList);
    // return the sum
    return sum;


}
