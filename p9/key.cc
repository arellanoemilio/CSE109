#include "key.h"


Key::Key (const char *s){
  word = s;
  hsh = hash();
}

Key::Key(const Word &w):word(w){
  hsh = hash();
}

ostream & operator<<(ostream & out, const Key &k){
  Word w = k.word;
  return out<<"["<<w<<", "<<k.hsh<<"]";
}

int Key::hash()const{
  int h = 0;
  // cout<<"h = "<<h<<endl;
  const int length = word.length();
  //  cout<<word<<endl;
  for(int i = 0; i < length;i++){
    h += (h+word[i])*257;
  }
  // cout<<"h = "<<h<<endl;
  return abs(h);
}

bool Key:: operator ==(const Key &k)const{
  // cout<<"Start == with key ="<<k<<endl;
  // cout<<hash()<<endl;
  if(hsh == k.hsh)
    return true;
  return false;
}

bool Key:: operator !=(const Key &k)const{
  if(word != k.word)
    return true;
  return false;
}
