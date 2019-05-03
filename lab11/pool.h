#ifndef POOL_H
#define POOL_H

#include <tr1/memory>
#include <string>
#include <cstdio>
using namespace std;

// KVPairs are pairs of strings: a key and its associated value,
//    with associated methods to get and set the key/value

// Pool provides access to an initialized pool of KVPairs,
//    granting unique access via methods request/release
//       (i.e. you can ask pool to give you one of its available
//        KVPairs using request, and when you're finished with the
//        KVPair you can return it to the pool using release)
//    it keeps a stack of the currently available KVPairs,
//        when requests come in it serves them off the top of stack,
//        and when releases come it it pushes them onto the stack
// Pool utilizes shared pointers, passed by reference

// the allocatable resource, a string key/value pair
class KVPair {
   private:
      string key, value;
   public:
      KVPair(string k="", string v="");
      void get(string &k, string &v);
      void set(string &k, string &v);
      ~KVPair();
};

template <class T>
// a pool of pre-created allocatable resources
class Pool {
   private:
      // the number of resources the pool can hold
      static const long poolSize = 10;
      // the number of resources currently available for requests
      long Available;
      // the collection of shared pointers to the data objects
      std::tr1::shared_ptr<T> avail[poolSize];
   public:

      // Pool allocates each of the data objects in avail[]
      //    and initializes Available to the poolSize
      Pool();

      // ~Pool simply displays how many resources were available
      //     and the total pool size
      ~Pool();

      // return the number of resources currently available
      long getAvail() { return Available; }

      // if Available is greater than 0,
      //    then decrement Available,
      //    copy the object in avail[Available] to d,
      //    reset the avail[Available] shared pointer,
      //    decrement Available, and return true
      // otherwise return false
      bool request(std::tr1::shared_ptr<T> &d);

      // if Available is less than the pool size,
      //    then copy the object in d to avail[Available],
      //    reset the d shared pointer,
      //    increment Available, and return true
      // otherwise return false
      bool release(std::tr1::shared_ptr<T> &d);
};

#endif

