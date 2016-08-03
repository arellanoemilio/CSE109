#ifndef KEY_H
#define KEY_H
#include "word.h"

class Key{
private:
  Word ky;
  int hsh;
  Key();
  void computeHash();
public:
  Key(const Word & w);
  Key(const char * str);
  int hash()const;
  const Word & key()const;
  friend bool operator==(const Key &k,const Key&v);
  friend bool operator!=(const Key &k,const Key&v);
  friend ostream& operator<<(ostream& out,const Key &k);
};
#endif
