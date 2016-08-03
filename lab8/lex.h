#ifndef LEX_H
#define LEX_H

#include "table.h"
#include "word.h"

//   ; indicates beginning of comment
class Lex{
public:
  static const int TABLELENGTH=27;
  static const int JUNK=-1, NUMBER=0, IDENTIFIER=1,PLUS=2,MINUS=3,TIMES=4,
    DIVIDE=5, IF=6, WRITE=7, READ=8, LBRACK=9, RBRACK=10, LPAR=11, RPAR=12, 
    BEGIN=13,SETEQ=14,GOTO=15, LT=16, GT=17, LE=18, GE=19,
    EQ=20, NE=21,EOLN=22,END=23,COLON=24,HALT=25,MODULO=26;  
  Lex();
  void setString(const Word &w);
  int next();
  bool atEnd(int t)const;
  bool atEnd()const;
  void reset(int k=0);
  Word word()const; 
  int position()const;
  int peek(); //return the next symbol, without moving past white space
private:
  static void check(bool b, const char *mess);
  Word str,currentWd;
  Table   lookUp;
  int loc;
  int alpha();
  int symbol();
  int number();
  void saveCurrent(int newLoc);
};
#endif
