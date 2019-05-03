#include "pool.h"
#include <cstdio>
#include <iostream>
#include <cctype>
#include <cstdlib>

// get a command choice from the user
char getCmd();

int main()
{
   printf("\nStart of main\n");
   Pool<KVPair> p;
   const long arrSize = 11;
   std::tr1::shared_ptr<KVPair> arr[arrSize];
   int currSize = 0;
   string k, v;
   char cmd;
   do {
      cmd = getCmd();
      if (cmd == 'g') {
         if (p.request(arr[currSize])) {
            printf("Resource request granted by pool\n");
            printf("Please enter a key and value for the new resource:\n");
            cin >> k >> v;
            arr[currSize]->set(k, v);
            arr[currSize]->get(k, v);
            printf("key/value set %s::%s\n", k.c_str(), v.c_str());
            currSize++;
         } else {
            printf("Resource request denied by pool\n");
         }
      } else if (cmd == 'r') {
         if (currSize > 0) {
            currSize--;
            arr[currSize]->get(k, v);
            if (p.release(arr[currSize])) {
               printf("released resource %s::%s\n", k.c_str(), v.c_str());
            } else {
               printf("unable to release resource %s::%s\n", k.c_str(), v.c_str());
            }
         } else {
            printf("No resources currently on tap\n");
         }
      }
   } while (cmd != 'q');
   printf("\nEnd of main\n\n");
   return 0;
}

// get a command choice from the user
char getCmd()
{
   char cmd;
   printf("\nEnter g to get a new KV pair,\n");
   printf("   or r to release the current one,\n");
   printf("   or q to quit\n");
   do {
     cmd = getc(stdin);
   } while (isspace(cmd));
   cmd = tolower(cmd);
   switch (cmd) {
      case 'g':
      case 'r':
      case 'q': return cmd;
      default:
         printf("\'%c\' is not a valid command\n", cmd);
         return getCmd();
   }
}
