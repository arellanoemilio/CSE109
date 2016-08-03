#ifndef REK_T
#define REK_T
#include <iostream>
using namespace std;

template<class X,class Y>
class Rek{
  X  key;
  Rek();
public:
  Y data;
  const X & getKey()const;
  Rek(const X &k,Y d=Y());
  Rek<X,Y> *next;
  template<class U,class V>
  friend ostream & operator<<(ostream &out,const Rek<U,V>&r);
};

template<class X,class Y>
const X & Rek<X,Y>::getKey()const{ 
      return key;
}

template<class X,class Y>
Rek<X,Y>::Rek(const X&k,Y d):key(k), data(d){next=NULL;}

template<class X,class Y>
ostream & operator<<(ostream & out, const Rek<X,Y>&r){
  return out<<"["<<r.key<<", "<<r.data<<"]";
}

#endif
