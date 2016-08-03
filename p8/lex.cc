#include "lex.h"

Lex::Lex():line(""), nextToken(""){
  linePtr = 0;
  fillTable();
}

void Lex::fillTable(){
  table["+"] = PLUS;
  table["-"] = MINUS;
  table["*"] = TIMES;
  table["/"] = DIVIDE;
  table["if"] = IF;
  table["write"] = WRITE;
  table["read"] = READ;
  table["["] = LBRACK;
  table["]"] = RBRACK;
  table["("] = LPAR;
  table[")"] = RPAR;
  table["begin"] = BEGIN;
  table["="] = SETEQ;
  table["goto"] = GOTO;
  table["<"] = LT;
  table[">"] = GT;
  table["<="] = LE;
  table[">="] = GE;
  table["=="] = EQ;
  table["!="] = NE;
  table[";"] = EOLN;
  table["end"] = END;
  table[":"] = COLON;
  table["halt"] = HALT;
  table["%"] = MODULO;
}

void Lex:: setString(Word word){
  line = word;
  linePtr = 0;
}

bool Lex:: atEnd(){
  if(linePtr >= line.length() || line[linePtr] == ';')
    return true;
  return false;
}

void Lex::reset(int i){
  linePtr = i;
}

int Lex:: next(){
  skipWhiteSpaces(linePtr);
  if(atEnd()){
     nextToken = ";";
     return table[nextToken];
  }
  else if(isAlph(line[linePtr])){
    nextToken = getAlphToken(linePtr);
    if(table.inTable(nextToken))
      return table[nextToken];
    return  IDENTIFIER;
  }
  else if(isNum(line[linePtr])){
    nextToken = getNumToken(linePtr);
    return NUMBER;
  }
  else{
    nextToken = getSymToken(linePtr);
    if(table.inTable(nextToken))
      return table[nextToken];
    return  JUNK;
  }
}

int Lex:: peek(){
  int i = linePtr;
  Word w;
  skipWhiteSpaces(i);
  if(atEnd()){
     w = ";";
     return table[w];
  }
  else if(isAlph(line[i])){
    w = getAlphToken(i);
    if(table.inTable(w))
      return table[w];
    return  IDENTIFIER;
  }
  else if(isNum(line[i])){
    w = getNumToken(i);
    return NUMBER;
  }
  else{
    w = getSymToken(i);
    if(table.inTable(w))
      return table[w];
    return  JUNK;
  }
}



Word Lex::getAlphToken(int &i){ 
  int size = 0;
  while( linePtr < line.length() && (isAlph(line[i])||isNum(line[i]))){
    size++;
    i++;
  }
  string s = line.toString();
  s = s.substr(i-size,size);
  return s.c_str();
}

Word Lex::getNumToken(int &i){
  int size = 0;
  while( i < line.length() && isNum(line[i])){
    size++;
    i++;
  }
  string s = line.toString();
  s = s.substr(i-size,size);
  return s.c_str();
}

Word Lex::getSymToken(int &i){
  int sym = line[i++];
  char* c = new char[2];
  switch(sym){ 
  case '<':
    if(!atEnd() && line[i] == '='){
      i++;
      return "<=";
    }
     c[0] = sym;
     c[1] = '\0';
  case '>':
    if(!atEnd() && line[i] == '='){
      i++;
      return ">=";
    }
     c[0] = sym;
     c[1] = '\0';
  case '=':
    if(!atEnd() && line[i] == '='){
      i++;
      return "==";
    }
     c[0] = sym;
     c[1] = '\0';
  case '!':
    if(!atEnd() && line[i] == '='){
      i++;
      return "!=";
    }
     c[0] = sym;
     c[1] = '\0';
  default:
     c[0] = sym;
     c[1] = '\0';
    }

  return c;
}

void Lex:: skipWhiteSpaces(int& i){
  while(i < line.length() && line[i] == ' '){
    i++;
  }
}

bool Lex:: isAlph(char ch){
  if(ch >= 'a' && ch <= 'z')
    return true;
  return false;
}

bool Lex:: isNum(char ch){
  if(ch >='0' && ch <= '9')
    return true;
  return false;
}

Word Lex:: word(){
  return nextToken;
}

int Lex:: position(){
  return linePtr;
}

