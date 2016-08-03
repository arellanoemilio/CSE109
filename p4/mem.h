/*
Emilio Arellano
CSE 109
Memory.h*/
#ifndef MEM_H
#define MEM_H
#include <iostream>
#include <cstdlib>
using namespace std;

/*the class represents a location of memory
  in which one can store integers*/
class Memory{
 private:
  bool def;
  int value;
 public:
  /*no arg constructor, memory stays undefined*/
  Memory();
  /*copy coinstructor creates a deep copy of Memory*/
  Memory(const Memory &m);
  /*1 arg constructor stores m into memory*/
  Memory(int m);
  /*resets the memory to the new int*/
  void set(int m);
  /*returns value stored in memory*/
  int get();
 private:
  /*ches if flag is false, if so then displays messege and terminates program*/
  void check(bool flag,string messege);
};
#endif
