#ifndef FULLPROG_H
#define FULLPROG_H

#include "progChip.h"

class FullProg:public ProgChip{

 public:
  FullProg();
  void runExpression();
  void doTerm();
  void doFactor();
};
#endif
