#ifndef KEY_H
#define KEY_H

#include <cmath>
#include "word.h"
#include <iostream>
using namespace std;
/*Key stores a key and a hash number unique to the key*/
class Key{
  Word word;
  int hsh;
  Key();
public:
  /*Post-condition: creates key with using word*/
  Key(const Word &w);
  /*Post-condition: creates key with using Char* */
  Key(const char *s);
  /*post-condition:calcultes the hash value of the key and */
  int hash()const;
  /*compares two keys that are equal.
    postreturns true if the hash value is equal
    else returns false*/
  bool operator ==(const Key & k)const;
  /*compares two keys that are not equal.
    returns true if the hash are not equal
    else returns false*/
  bool operator !=(const Key & k)const;
  /*outpus the key and its hash number*/
  friend ostream & operator<<(ostream & out,const Key &k);  
};

#endif
