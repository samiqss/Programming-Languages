#include "pool.h"

KVPair::KVPair(string k, string v)
{
   key = k;
   value = v;
}

void KVPair::get(string &k, string &v)
{
    k = key;
    v = value;
}

void KVPair::set(string &k, string &v)
{
   key = k;
   value = v;
}

KVPair::~KVPair()
{
   printf("KVPair destructor: %s::%s\n", key.c_str(), value.c_str());
}

template <class T>
Pool<T>::Pool()
{
   Available = poolSize;
   for (int i = 0; i < poolSize; i++) {
       avail[i].reset(new T);
   }
}

template <class T>
Pool<T>::~Pool()

{
   printf("\nPool destructor, %ld of %ld resources available\n", Available, poolSize);
}

template <class T>
bool Pool<T>::request(std::tr1::shared_ptr<T> &d)
{
   if (Available < 1) return false;
   Available--;
   d = avail[Available];
   avail[Available].reset();
   return true;
}

template <class T>
bool Pool<T>::release(std::tr1::shared_ptr<T> &d)
{
   if (Available < poolSize) {
      avail[Available] = d;
      Available++;
      d.reset();
      return true;
   } else return false;
}

template class Pool<KVPair>;
