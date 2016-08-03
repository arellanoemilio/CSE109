#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Word{
private:
  int size;
  char *wd;
public:
  static const int SIZE=10;
  Word();
  Word(char ch);
  Word(const char*ch);
  Word(const Word &w);
  ~Word();
  char & operator[](int index);
  char operator[](int index)const;
  const Word & operator=(const Word&w);
  const char* toString()const;

  //Convert the int k to an instance of Word
  //Preconditions: k>=0. Don't deal with negative ints
  //Postcondition: wd has the digits of k; size=number of digits
  static Word fromInt(int k);
  int toInt()const;
  friend bool operator<(const Word &w,const Word&v);
  friend bool operator<=(const Word &w,const Word&v);
  friend bool operator>(const Word &w,const Word&v);
  friend bool operator>=(const Word &w,const Word&v);
  friend bool operator!=(const Word &w,const Word&v);
  friend bool operator==(const Word &w,const Word&v);
  friend ostream & operator<<(ostream &out,const Word &w);
  friend istream & operator>>(istream &in,Word & w); //eoln or eof as terminator
  int length()const;
private:
  void copy(const char *ch);
  static void check(bool b, const char *ch);
};  

#endif
