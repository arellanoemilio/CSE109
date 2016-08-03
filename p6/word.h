#ifndef WORD_H
#define WORD_H
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;
/*this is a wrapper class for strings*/
class Word{
private:
  char *wd;
  int size;
  /*checks flag, if flg is false then the outputs mess and chrashes program*/
  static void check(bool b, const char * mess);
public:
  /*Postcondition: word with emtpty string is created*/
  Word();
  /*postcondition: copuy constructor creates a deep copy of w*/
  Word(const Word &w);
  /*postcondition: word containing string ch is created*/
  Word(const char *ch);
  /*postcondition: word crontaingn strin ch is created*/
  Word(char ch);

  //precondition: wd is defined
  ~Word();

  /*returns the reference to the character at index n*/
  char & operator[](int n);
  /*retuns const copy of characted at index n*/
  char operator[](int n)const;
  /*postcondition: sets the string of the calling Word
    equal the the string contained in w*/
  const Word & operator=(const Word & w);
  /*returns length of the word*/
  const int length()const;
  /*retunrs the Word as a char* */
  char* toString();
  /*returns the word as an in only if the word contains an unsinged int*/
  int toInt();
  /*saves an int to a Word*/
  Word fromInt(int i);
  
  /*returns >0 if a is less than b else retuns 0*/
  friend bool operator<(const Word &a,const Word &b);
  /*returns >0 if a is greater than b else retuns 0*/
  friend bool operator>(const Word &a,const Word &b);
  /*returns >0 if a is less than or equal to b else retuns 0*/
  friend bool operator<=(const Word &a,const Word &b);
  /*returns >0 if a is greater than or equal to b else retuns 0*/
  friend bool operator>=(const Word &a,const Word &b);
  /*returns >0 if a is equal b else retuns 0*/
  friend bool operator==(const Word &a,const Word &b);
  /*returns >0 if a is not equal to b else retuns 0*/
  friend bool operator!=(const Word &a,const Word &b);
  /*reads and saves an input from in into a Word w*/
  friend istream & operator>>(istream &in,Word & w);
  /*outputs to out the string in Word*/
  friend ostream & operator<<(ostream &out,const Word &w);
private:
  /*postcondition: the calling word has  str saved as its string*/
  void copy(const char * str);
};
#endif
