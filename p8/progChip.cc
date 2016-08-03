#include "progChip.h"

ProgChip::ProgChip():Chip(),lex(),lexInput(){
  inputTok = progSize = pc =tok =varCounter = 0;
}

void ProgChip::load(ifstream &in){
  check(in.good(),"Error: ProgChip: load: file cannot be read");
  cout<<"Declaring variables"<<endl;
  runDeclaration(in);
  cout<<"loading Program"<<endl;
  loadProgram(in);
  setInput(in);
  cout<<"Program succesfully loaded...\n----------------------------"<<endl;
}

void ProgChip::runDeclaration(ifstream &in){
  readLine(in);
  while(in.good() && tok != Lex::BEGIN){
    if(tok == Lex::IDENTIFIER)
      if(lex.peek() == Lex::EOLN){
	cout<<lex.word()<<endl;
	check(!var.inTable(lex.word()),"Error: ProgChip: runDeclaration():Duplicate identifier");
	addVar();
      }
    readLine(in);
  }
  check(tok == Lex::BEGIN, "Error: ProgChip: runDeclaration(): invalid syntax, BEGIN expected");
    tok = lex.next();
    check(tok == Lex::EOLN,"Error: ProgChip: runDeclaration(): invalid Syntax, EOLN expected");
  
}

void ProgChip::readLine(ifstream &in){
  in >> program[progSize];
  lex.setString(program[progSize]);
  tok = lex.next();
}

void ProgChip::addVar(){
  check(varCounter < 100,"Error: ProgChip: addVar():Heap Overflow");
  var[lex.word()] = varCounter;
  memory[varCounter].set(0);
  varCounter++;
}

void ProgChip::loadProgram(ifstream &in){
  progSize =0;
  readLine(in);
  while(in.good() && progSize<MAX_SIZE && tok != Lex::END){
    if(tok != Lex::EOLN){
      cout<<progSize<<":"<<program[progSize]<<endl;
      checkLable();
    }
    progSize++;
    readLine(in);
  }check(tok == Lex::END,"Error: ProgChip: loadProgram():program expects missing 'end'");
    
}

void ProgChip::checkLable(){
  if(tok == Lex::IDENTIFIER && lex.peek() == Lex::COLON){
    check(!lables.inTable(lex.word()),"Error: ProgChip: runDeclaration():Duplicate identifier");
    lables[lex.word()] = progSize;
  }
}

void ProgChip:: setInput(ifstream &in){
  Word w;
  in >> w;
  lexInput.setString(w);
  inputTok = lexInput.next();
}

void ProgChip::run(bool verbose){
  step = pc = 0;
  cout<<"Running...\n"<<endl;
  lex.setString(program[pc]);
  tok = lex.next();
  skipLable();
  while(tok != Lex::END && tok != Lex::HALT){
    doLine();
    if(verbose)
      cout<<"[Step= "<<step<<", line= "<< pc <<"]:"<<program[pc]<<endl; 
    lex.setString(program[++pc]);
    tok = lex.next();
    skipLable();
  }check(tok == Lex::HALT,"ERROR: progChip: run(); program ran past 'end'");
}

void ProgChip:: skipLable(){
  // cout<<"skip lable"<<endl;
  if(tok == Lex::IDENTIFIER && lex.peek() == Lex::COLON){
    tok = lex.next();
    tok = lex.next();
  }
}

void ProgChip::doLine(){
  // cout<<"pc = "<<pc<<endl;
  step++;
  switch(tok){
  case Lex::IDENTIFIER: doEqual(); break;
  case Lex::IF: doIf(); break;
  case Lex::READ: doRead(); break;
  case Lex::WRITE: doWrite(); break;
  case Lex::GOTO: doGoTo(); break;
  case Lex::EOLN:  break;
  default: check(false,"Error: ProgChip():doLine():Line is not syntactically correct");
  }
}

void ProgChip::doEqual(){
  // cout<<"start do equal"<<endl;
  check(var.inTable(lex.word()),"Error: ProgChip: doEqual():Identifier not found in table");
  int memLoc = var[lex.word()];
  if(lex.next() == Lex::SETEQ){
    tok = lex.next();
    runExpression();
    store(memLoc);
  }else
    check(false,"Error:ProgChip: doEqual():invalid syntax, = expected");
}

void ProgChip::runExpression(){
  // cout<<"start run expression"<<endl;
  if(tok == Lex::NUMBER)
    accu = lex.word().toInt();
  else if(tok == Lex::IDENTIFIER){
    check(var.inTable(lex.word()),"Error: ProgChip: doEqual():Identifier not found in table");
    accu = memory[var[lex.word()]].get();      
  }else
     check(false,"Error: ProgChip: runExpression(): Invalid syntax");
  tok = lex.next();
}


void ProgChip::doIf(){
  // cout<<"start do if"<<endl;
  tok = lex.next();
  runExpression();
  push();
  int boolOpt = tok;
  tok = lex.next();
  runExpression();
  push();
  top(-2);
  pop();
  top(-1);
  pop();
  bool flag;
  switch(boolOpt){
  case Lex::LT:flag = (register1 < register2);break;
  case Lex::GT:flag = (register1 > register2);break;
  case Lex::LE:flag = (register1 <= register2);break;
  case Lex::GE:flag = (register1 >= register2);break;
  case Lex::EQ:flag = (register1 == register2);break;
  case Lex::NE:flag = (register1 != register2);break;
  default:
    check(false,"Error: ProgChip: doIf():Invalid Syntax");
  }
  if(flag)
    doGoTo();
  tok = lex.next();
}

void ProgChip::doGoTo(){
  // cout<<"start go to"<<endl;
  check(tok == Lex::GOTO, "Error: ProgChip: doGoTo():invalid syntax");
  tok = lex.next();
  check(tok == Lex::IDENTIFIER, "Error: ProgChip: doGoTo():invalid syntax");
  pc = lables[lex.word()]-1;
}

void ProgChip::doRead(){
  // cout<<"start do read"<<endl;
  tok = lex.next();
  
  check(tok ==Lex::IDENTIFIER,"Error: ProgChip: doRead(): invalid syntax,IDENTIFIER expected");
  int memLoc = var[lex.word()];
  getInput();
  store(memLoc);
  cout<<"INPUT<---"<<memory[memLoc].get()<<endl;
  tok = lex.next();
}

void ProgChip:: doWrite(){
  //  cout<<"start do write"<<endl;
  tok = lex.next();
  runExpression();
  cout << "\tOUTPUT--->"<<accu<<endl;
  tok = lex.next();
}
void ProgChip:: getInput(){
  check(inputTok == Lex::NUMBER ||inputTok == Lex::MINUS, "Error: ProgChip: getInput():invalid input");
  if(inputTok == Lex::NUMBER)
    accu = lexInput.word().toInt();
  else if(inputTok == Lex::MINUS){
    inputTok = lexInput.next();
    check(inputTok == Lex::NUMBER, "Error: ProgChip: getInput():invalid input");
    accu = lexInput.word().toInt()*(-1);
  }
  inputTok = lexInput.next();
}


void ProgChip::check(bool flag, string mess1,string mess2){
  if(!flag){
    cout<<mess1<<mess2<<endl;
    exit(0);
  }
}

