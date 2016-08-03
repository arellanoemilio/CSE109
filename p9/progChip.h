/*Emilio Arellano
  CSE 109
  ProgChip.h     */
#ifndef PROGCHIP_H
#define PROGCHIP_H

#include "chip.h"
#include "lex.h"
#include <fstream>
/* progChip is a subclass of Chip that can read in a file of language tiny and interpret it */
class ProgChip:public Chip{
 public:
  static const int MAX_SIZE = 100;
  /* Inicializes progChip*/
  ProgChip();
  /*pre-condition: in  is a file containing a program written in tiny.
    Post-Condition: the program is loaded and stored in ProgChip*/
  void load(ifstream &in);
  /*pre-contition: program is loaded
   post-condition: it interprests the program loaded
  if verbose is true it eco's the the the program as it
  interprets it*/
  void run(bool verbose);
  static void check(bool flag, string mess1,string mess2="");

 protected:
  Table var;
  Table lables;
  Word program[MAX_SIZE];
  int inputTok, progSize,pc,tok,varCounter,step;
  Lex lex,lexInput;

  /*loads every line of the program to the array "program"*/
  void loadProgram(ifstream &in);
  /*reads the next line from the file*/
  void readLine(ifstream &in);
  /*it saves the variables in the table var*/
  void runDeclaration(ifstream &in);
  /*it reads the next line of the program and executes it*/
  void doLine();
  
  void doIf();
  virtual void runExpression();
  void doGoTo();
  void doHalt();
  void doRead();
  void doWrite();
  void doEqual();
  void getInput();
  void setInput(ifstream &in);
  void checkLable();
  void addVar();
  void skipLable();

};
#endif
