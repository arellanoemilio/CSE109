/*
Emilio Arellano
CSE 109
Memory.cc*/

#include "mem.h"

Memory:: Memory(){
  def = false;
}

Memory:: Memory(const Memory & m){
  def = m.def;
  value = m.value;
}

Memory:: Memory(int m){
  value = m;
  def = true;
}

void Memory:: set(int m){
   def =true;
  value = m;
}

int Memory:: get(){
  check(def,"Error: Memory: get(): Memory not defined");
  return value;
}


void Memory:: check(bool flag, string  messege){
  if(!flag){
    cerr<<messege<<endl;
    exit(1);
  }
}
