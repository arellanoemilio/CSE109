/*
Emilio Arellano
CSE 109
Chip.cc
*/

#include "chip.h"

Chip:: Chip():ALU(){
 size = memory;
 size = size+( MEMORY_SIZE - 1);
}

Chip:: Chip(int reg1):ALU(reg1){
 size = memory;
 size = size+( MEMORY_SIZE - 1); 
}

Chip:: Chip(int reg1, int reg2):ALU(reg1,reg2){
 size = memory;
 size = size+( MEMORY_SIZE - 1);
}

Chip:: Chip(const Chip & c):ALU(c.register1,c.register2){
 accu = c.accu;
 size = memory;
 size = size+( MEMORY_SIZE - 1); 
 int copyCounter = 1;
 const Memory *i = c.memory;
 for(; i <= size; i--){
   memory[MEMORY_SIZE - copyCounter]  =  *i;
   size--;
 }
}

Chip & Chip:: push(){
  check(size > &memory[99], "Error: chip: Push: stack is full");
  size->set(accu);
  size--;
  return *this;
}

Chip & Chip:: pop(){
  check(size < (memory+MEMORY_SIZE), "Error: chip: pop: cannot pop when stack is empty");
  size++;
  return *this;
}

Chip & Chip:: pop(int reg){
  check(size < (memory+MEMORY_SIZE), "Error: chip: pop: cannot pop when stack is empty");
  switch(reg){
  case -1: 
    top(-1);
   break;
  case -2:
    top(-2);
    break;
  default:
    check(reg >= 0 && reg < MEMORY_SIZE,"Error: Chip: pop: first parameter: not a valid entry");
    top(reg);
    break;
  }
  size++;
  return *this;
}

Chip & Chip:: top(int reg){
  check(size < (memory+MEMORY_SIZE),"Error: Chip: top: cannot top when stack is empty");
  switch(reg){
  case -1:
    register1 = (size+1)->get();
    break;
  case -2:
    register2 = (size+1)->get();
    break;
 default:
    check(reg >= 0 && reg < MEMORY_SIZE,"Error: Chip: top: first parameter: not a valid entry");
    memory[reg] = (size+1)->get();
    break;
  }
  return *this;
}

Chip & Chip:: store(int loc){
  check(loc<100 && loc >=0, "Error: chip: store: loc is not within the bound of the memory locations");
  memory[loc] = accu;
  return *this;
}

Chip & Chip:: load1(int loc){
  check(loc<100 && loc >=0, "Error: chip: load1: loc is not within the bound of the memory locations");
  register1 = memory[loc].get();
  return *this;
}

Chip & Chip:: load2(int loc){
  check(loc<100 && loc >=0, "Error: chip: load2: loc is not within the bound of the memory locations");
  register2 = memory[loc].get();
  return *this;
}


void Chip:: check(bool flag, string messege){
  if(!flag){
    cout<<messege<<endl;
    exit(1);
  }
}

