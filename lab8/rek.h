/*Implement the ADT for a record ptr to be used in a hash table
  that uses linked lists to handle collisions.
 */
#ifndef REK_H
#define REK_H
#include <iostream>
#include "key.h"
using namespace std;

class Rek{
private:
  Key key;
public:
  int data;
  Rek*next;
  //  Rek(const Word&w,int d=0);
  Rek(const Key &k,int d=0);
  Rek(const Rek &r);
  ~Rek();
  const Key & getKey()const;
  friend ostream & operator<<(ostream &out,const Rek &r);
};

#endif
