/*
Emilio Arellano
CSE 109
Chip.h*/
#ifndef CHIP_H
#define CHIP_H
#include <iostream>
#include <cstdlib>
#include "alu.h"
#include "mem.h"
using namespace std;

/*this class is sub class of chip and is able to store values
and retreve values into and from an allocated  memory location
and a stack of memory*/
class Chip:public ALU{
 private:
  const static int MEMORY_SIZE = 200;
  Memory memory[MEMORY_SIZE];
  Memory *size;
  

 public:
  /* no arg constructor fills registers with garbage*/
  Chip();
  /* one arg construtor sets register 1 equal to arg 1
   and sets register 2 equal to 0*/
  Chip(int reg1);
  /*two arg constructor sets register 1 equal to arg 1 
   and sets register 2 equal to arg 2*/
  Chip(int reg1,int reg2);
  /*Copy constructor creates a deep copy of the arg passed*/
  Chip(const Chip &c);
  /*push contents of accumulator onto stack*/
  Chip & push();
  /*put top of stack in some memory location or in one
   of the two registers (for -1 or -2), but do not pop*/
  Chip & top(int reg);
  /* pop the top of the stack and discard */
  Chip & pop();
  /*pop the top of the stack to a memory
   location or to a register (for -1 or -2)*/
  Chip & pop(int reg);
  /*store accumulator in some memory location*/
  Chip & store(int loc);
  /*load contents of some memory location into reg1*/
  Chip & load1(int loc);
  /*load contents of some memory location into reg2*/
  Chip & load2(int loc);

 private:
  //checks boolean, if false displays messege and exits program
  void check(bool flag, string messege);
};

#endif
