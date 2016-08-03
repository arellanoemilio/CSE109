#ifndef REK_H
#define REK_H
#include "key.h"

class Rek{
  Key key;
  Rek();
public:
  /*this is the value stored for the rek*/
  int data;
  /*Post-Condition: returns the key of the rek*/
  const Key & getKey()const;
  /*Post-Condition: creates an instance of reck using the key and stores int d as its data*/
  Rek(const Key &k,int d=int(0));
  /*next points to a next rek when these are used in a linked list*/
  Rek *next;
  /*Post-Condition: outputs the rek inside of two brackets by first  outputing the key and then the data*/
  friend ostream & operator<<(ostream &out,const Rek&r);
  

};

#endif
