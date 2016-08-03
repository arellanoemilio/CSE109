/*
  Emilio Arellano
  CSE 109
  ALU.h
 */
#ifndef ALU_H
#define ALU_H
#include <iostream>
#include <cstdlib>
using namespace std;

/*this class stors two values and performs diferent opereations with the values and then stores the 
in the acumulator of the CPU*/
class ALU{

protected:
  int register1,register2, accu;

public:
  const static int ADD = 0;
  const static int SUB = 1; 
  const static int MUL = 2; 
  const static int DIV = 3;
  const static int MOD = 4;

public:
  /*no arg construction*/
  ALU();
  
  /*copy consturctor*/
  ALU(const ALU & r);
  
  /*one arg constructor, it sorts the arg into the first register and then sets the second register and
    the acumulator to zero. */
  ALU(int i);
  
  /*two arg constuctos, sets the first registrer to the first agument
    and the second register to the second constructor while the 
    accumulator is kept with trash*/
  ALU(int i, int j);

  /* This method takes in an operation and stors the value obtained
    from the operation into the accumulator */
  ALU & op(int f);
  
  /* sets the value of register 1 to i*/
  ALU & set1(int i);

  /*sets the value of register 2 to i*/
  ALU & set2(int i);

  /*Returns the value of the first register*/
  int get1();
 
  /*returns the valure of the second register*/
  int get2();

  /*returns the valure of the accumulator*/
  int acc();

  /*override the << operator to print out the values of the ALU */
  friend ostream & operator << (ostream & out, const ALU & a);

};
#endif
