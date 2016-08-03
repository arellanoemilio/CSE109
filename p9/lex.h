#ifndef LEX_H
#define LEX_H
#include <cstring>
#include <iostream>
#include "word.h"
#include "table.h"
using namespace std;


/*This class reads in a word and tokenizes it */
class Lex{
 private: 
  Word line, nextToken;
  int linePtr;
  Table table;
  
 public:
  static const int JUNK = -1,NUMBER = 0, IDENTIFIER = 1, PLUS = 2, MINUS = 3, TIMES = 4, DIVIDE = 5, IF = 6, WRITE = 7, READ = 8,
    LBRACK =9, RBRACK = 10, LPAR = 11, RPAR = 12, BEGIN = 13, SETEQ = 14, GOTO = 15, LT = 16, GT = 17, LE = 18, GE = 19, EQ = 20, NE = 21,
    EOLN = 22, END = 23, COLON = 24, HALT = 25, MODULO = 26;

 private:
  void fillTable();
  void skipWhiteSpaces(int& i);
  bool isAlph(char ch);
  bool isNum(char ch);
  Word getAlphToken(int &i);
  Word getNumToken(int &i);
  Word getSymToken(int &i);

 public:
  /*Post -condition: constructs a lex with and empty line and no tokens*/
  Lex();
  /*post-condition: stores Word word and prepares it to be tokenized*/
  void setString(Word word);
  /*post-condition: retuns true if the line has no more tokens to return*/
  bool atEnd();
  /*post-condition:resets the line pointer to position int i to start tokenizinf from that position again*/
  void reset(int i= 0);
  /*post-condition: returns the word of the current token*/
  Word word();
  /*post-conditon:returns the position of the current end of the current token*/
  int position();
  /*post-condition: returns the int value of the next token*/
  int peek();
  /*post-condition: retuns the int value of the current token*/
  int next();
};

#endif
