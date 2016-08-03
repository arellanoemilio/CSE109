#ifndef REK_H
#define REK_H
#include "key.h"

class Rek{
  Key key;
  Rek();
public:
  int data;
  const Key & getKey()const;
  Rek(const Key &k,int d=int(0));
  Rek *next;
  friend ostream & operator<<(ostream &out,const Rek&r);
  

};

#endif
