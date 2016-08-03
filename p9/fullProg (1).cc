#include "fullProg.h"
FullProg:: FullProg():ProgChip(){}

void FullProg:: runExpression(){
  //  cout<<"run Expression 1"<<endl;
  doTerm();
  while(tok == Lex::PLUS || tok == Lex::MINUS){
    int ope = tok;
    tok = lex.next();
    doTerm();
    pop(-2);
    pop(-1);
    op(ope);
    push();
  }
}
 
void FullProg:: doTerm(){
  //  cout<<"do term"<<endl;
  doFactor();
  while(tok==Lex::DIVIDE|| tok == Lex::MODULO || tok == Lex::TIMES){
    int ope = tok;
    tok = lex.next();
    doFactor();
    pop(-2);
    pop(-1);
    op(ope);
    push();
  }
}

void FullProg:: doFactor(){
  //  cout<<"do factor"<<" "<< lex.word()<<endl;
  if(tok==Lex::LPAR){
    tok = lex.next();
    runExpression();
    check(tok == Lex::RPAR,"Error: FullProg: doFactor(): invalid syntax, ) expected");
    tok = lex.next();
  }else{
    ProgChip::runExpression();
  }
  //  cout<<"end factor"<<endl;

}
