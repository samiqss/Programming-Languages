#include <stdio.h>

// global variables to remember the memory addresses and values
//    of the x's examined in this program
unsigned long* addresses[6] = { 0, 0, 0, 0, 0, 0 };
unsigned long  values[6] = { 0, 0, 0, 0, 0, 0 };

// global variable x and constant x2
unsigned long x = 1;
const unsigned long x2 = 1000;

// try using x as an enumerated value
// enum { x };  <== causes compilation error, x re-defined as different kind of symbol, hence commented out

// f1 experiments with scoping
void f1(unsigned long x);

// f2 experiments with constants
void f2(unsigned long* x);

// display the address and value for x's encountered so far,
//    as well as the values *currently* at those addresses
void displayStatus(const char str[], unsigned long x);

int main()
{
   // grab the address/value of the global x
   addresses[4] = &x;
   values[4] = x;
   displayStatus("early in main", x);

   // within a block, create a constant local x, grab it's address/value
   {
      const unsigned long x = 50;
      addresses[5] = (unsigned long*)(&x);
      values[5] = x;
      displayStatus("block in main before f2 call", x);
      // invoke f2 to see if we can corrupt a local constant
      f2((unsigned long*)(&x));
      // try the same thing on a global constant
      // f2((unsigned long*)(&x2));  <=== causes segmentation fault, hence commented out
      displayStatus("block in main after f2 call", x);
   }
   x++;
   displayStatus("main between f2 and f1 calls", x);

   // invoke f1 to test its scope handling
   f1(x);

   displayStatus("end of main", x);
   printf("\n");
   return 0;
}

// display the address and value for x's encountered so far,
//    as well as the values *currently* at those addresses
void displayStatus(const char str[], unsigned long x)
{
   printf("\nDisplay status called from %s, current x value %ld (hex %lx)\n", str, x, x);
   printf("%-29s %-16s %-16s %-16s %s\n", "Description", "Memory Address", "Stored Value", "Curr Val @Addr", "(Hex val)");
   if (addresses[0] != 0) {
      printf("%-29s %-16p %-16ld %-16ld (0x%lx)\n", "f1 parameter x", addresses[0], values[0], *(addresses[0]), *(addresses[0]));
   }
   if (addresses[1] != 0) {
      printf("%-29s %-16p %-16ld %-16ld (0x%lx)\n", "f1 x local to for", addresses[1], values[1], *(addresses[1]), *(addresses[1]));
   }
   if (addresses[2] != 0) {
      printf("%-29s %-16p %-16ld %-16ld (0x%lx)\n", "f1 x local to while (in for)", addresses[2], values[2], *(addresses[2]), *(addresses[2]));
   }
   if (addresses[6] != 0) {
      printf("%-29s %-16p %-16ld %-16ld (0x%lx)\n", "f1 local to do-whle (in for)", addresses[6], values[6], *(addresses[6]), *(addresses[6]));
   }
   if (addresses[3] != 0) {
      printf("%-29s %-16p %-16p %-16p (0x%lx)\n", "f2 ptr parameter x", addresses[3], values[3], *(addresses[3]), *(addresses[3]));
   }
   if (addresses[7] != 0) {
      printf("%-29s %-16p %-16ld %-16ld (0x%lx)\n", "f2 x local in if", addresses[7], values[7], *(addresses[7]), *(addresses[7]));
   }
   if (addresses[4] != 0) {
      printf("%-29s %-16p %-16ld %-16ld (0x%lx)\n", "global x", addresses[4], values[4], *(addresses[4]), *(addresses[4]));
   }
   if (addresses[5] != 0) {
      printf("%-29s %-16p %-16ld %-16ld (0x%lx)\n", "block local const x in main", addresses[5], values[5], *(addresses[5]), *(addresses[5]));
   }
}

// f1 experiments with scoping
void f1(unsigned long x)
{
   // grab the address/value for parameter x
   addresses[0] = &x;
   values[0] = x;
   displayStatus("early in f1", x);

   // try creating a local x
   // unsigned long x;  <== causes compilation error, x re-declared as diffent kind of symbol, hence commented out

   // examine scoping of nested loops
   for (x = 20; x < 22; x++) {
       unsigned long x = 30;
       // grab the address/value for the outer loop-local x
       addresses[1] = &x;
       values[1] = x;

       // first loop (count # iterations it goes through)
       unsigned long iterations = 1;
       displayStatus("f1 inside for, before while", x);
       while ((x < 33) && (iterations < 5)) {
          unsigned long x = 40;
          // grab the address/value for the inner while loop-local x
          addresses[2] = &x;
          values[2] = x;
          displayStatus("f1 in while, in for, before increments", x);
          x++;
          iterations++;
       }
       printf("while loop went through %ld iterations\n", iterations-1);

       displayStatus("f1 inside for, after while", x);

       // second loop
       iterations = 0;
       do {
          unsigned long x = 50;
          // grab the address/value for the inner do-while loop-local x
          addresses[6] = &x;
          values[6] = x;
          displayStatus("f1 in do-while, in for", x);
          // alter the local x and the iterator
          x += 2;
          iterations++;
       } while (iterations < 2);
       displayStatus("f1 inside for, after do-while", x);
   }

   displayStatus("end of f1", x);
}

// f2 experiments with constants
void f2(unsigned long* x)
{
   // grab the address/value for pointer parameter x
   addresses[3] = (unsigned long*)(&x);
   values[3] = (unsigned long)(x);
   displayStatus("start of f2", (unsigned long)(x));

   // use a local x within an if block
   if (1) {
      unsigned long x = 100;
      addresses[7] = (unsigned long*)(&x);
      values[7] = (unsigned long)(x);
      displayStatus("f2 within if block", (unsigned long)(x));
   }

   // alter the value pointed at, then the value of the pointer
   *x += 5;
   x++;
   displayStatus("end of f2", (unsigned long)(x));
}

