#include "rek.h"

const Key & Rek::getKey()const{return key;}

Rek::Rek(const Key&k,int d):key(k),data(d){next=NULL;}

ostream & operator<<(ostream & out, const Rek&r){
  return out<<"{"<<r.key<<", "<<r.data<<"}";
}

