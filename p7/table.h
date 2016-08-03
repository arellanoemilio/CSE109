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
  /*Post-Condition: constructs a table of size of the smallest prime number after int s*/
  Table(int s = 57);
  /*Post-Condition: deconstructs the table*/
  ~Table();
  
  /* Post-Condition: if the flag is false outputs string mess and exits program*/
  void check(bool flag, string mess)const;
  /*post-Condition: if rek with key k is not found in the table, then a new instance of rek with the key k is constructed and stored
   in the table then its reference to its data is returned. If a rek with key k already exitst in the table then returns a reference
  to the data of the existing rek with key k.*/
  int & operator [](const Key & k);
  /*post-Condition: if no rek with key k is found in the table the program crashes, otherwise returns the value stored as data in the
   rek with the key k in the table*/
  int  operator [](const Key & k)const;
  /*post-condition: retuns true if key w is found in any of the reks in the table, otherwise returns false*/
  bool inTable(const Key  &w)const;
  /*post-condition: prints out the key inside of brackets first the word of the key and then its hash number*/
  friend ostream& operator <<(ostream& out,const Table & t); 
  
 private:
  bool isprime(int i);
  Rek * store(Rek *r);
};


#endif
