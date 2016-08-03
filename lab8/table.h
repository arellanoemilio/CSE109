#ifndef TABLE_H
#define TABLE_H
#include <cstdlib>
#include <iostream>
using namespace std;
#include "rek.h"
#include "key.h"

class Table{
private:
  Rek **table;
  int size;
public:
  static void check(bool b,const char*mess);
  static const int SIZE=101;
  Table(int k=SIZE);
  Table(const Table &t);
  ~Table();
  int getPrime(int j); //return smallest prime larger than j
  bool prime(int j); //is j prime
  const Table & operator=(const Table &t);
  bool inTable(const Key&k)const;
  int & operator[](const Key &k);
  int operator[](const Key&k)const;
  friend ostream & operator<<(ostream &out,const Table &t);
};
#endif
