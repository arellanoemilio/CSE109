/*
  Emilio Arellano
  CSE 109
  ALU.cc
 */

#include "alu.h"

ALU:: ALU(){}

ALU:: ALU(int i, int j){
  register1 = i;
  register2 = j;
}

ALU:: ALU(int i){
  register1 = i;
  register2 = 0;
  accu = 0;
}

ALU:: ALU(const ALU & a){
  register1 = a.register1;
  register2 = a.register2;
  accu = a.accu;
}

ALU & ALU:: op(int f){
  switch(f){
  case ALU:: ADD: accu = register1 + register2; break;
  case ALU:: SUB: accu = register1 - register2; break;
  case ALU:: MUL: accu = register1 * register2; break;
  case ALU:: DIV:
    if(register2 != 0) 
      accu = register1 / register2;
    else
      cout<<"Error: ALU division: division by zero"<<endl;
    break;
  case ALU:: MOD: 
    if(register2 !=0)
      accu = register1 % register2;
    else
      cout<<"Error: ALU Mod: mod by zero"<<endl;
    break;
  default: cout<<"Error: ALU op: parameter out of range"<<endl;
           exit(1);
	   break;
  }
  return *this;
}

ALU & ALU:: set1(int i){
  register1 = i;
  return *this;
}

ALU & ALU:: set2(int i){
  register2 = i;
  return *this;
}

int ALU:: get1(){
  return register1;
}

int ALU:: get2(){
  return register2;
}

int ALU:: acc(){
  return accu;
}

ostream & operator << (ostream & out, const ALU &a){
  out<<"{acc: "<<a.accu<<", reg1: "<<a.register1<<", reg2: "<<a.register2<<"}"<<endl;
  return out;
}

