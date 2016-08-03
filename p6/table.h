#ifndef TABLE_H
#define TABLE_H

#include "rek.h"
#include "key.h"

/*Table is an object that stores an array of linked lists of Reks*/
class Table{
 private:
  typedef Rek** TablePtr;
  int size;
  TablePtr table;
 
 public:
  Table(int s);
  ~Table();
  
  void check(bool flag, string mess)const;
  int & operator [](const Key & k);
  int  operator [](const Key & k)const;
  bool inTable(const Key  &w)const;
  
  friend ostream& operator <<(ostream& out,const Table & t); 
  
 private:
  bool isprime(int i);
  Rek * store(Rek *r);
};


#endif
