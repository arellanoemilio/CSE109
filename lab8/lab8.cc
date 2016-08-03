#include "lex.h"

/*Purpose: check syntax of input to determine whether it satisfies the
  syntax of the diagrams given by
  www.cse.lehigh.edu/~edk/goodLine.jpg.
  PreCondition: lex has stored the current line to process
                tok is the next token to process
  PostCondition: if processing succeeded, tok has the next token to
                 process, else error message has been written to cout
		 and tok is not guaranteed, but processing has stopped
  Return: true if and only if processing is still succeeding
*/
bool goodLine(Lex &lex,int &tok);

/*if b is true return true. if b is false, write diagnostic message
  and return false */
bool check(bool b, const char *mess);

/* Purpose: get the next value of tok (but recall lex stalls at EOLN)
   and if not at EOLN write out the symbol corresponding to tok
*/
void next(Lex&lex,int& tok);

bool doA(Lex &l, int &tok);

int main(){
  Lex lex;
  int tok;
  const char *line[]={
            "()<>[]",
	    "<<>>",
            "<<>(()[])>",
	    "<<>(()[t])>",
	    "<<]]",
	    "(<>>",
	    "[[<>()<>))",
	    "<<>(()[])><><>()"};
  for(int j=0;j<8;j++){
    cout<<"\nSetting '"<<line[j]<<"'\n         ";
    lex.setString(line[j]);
    next(lex,tok);
    if(goodLine(lex,tok))
      if(check(tok==lex.EOLN,"EOLN"))
        cout<<"\nSyntactically correct\n";
  }
}

bool check(bool b, const char *mess){
  if(!b){
    cout<<"\nError on line, Expected: '"<<mess<<"'\n";
    return false;
  }
  return true;
}

void next(Lex&lex,int& tok){
    tok=lex.next();
    if(tok!=lex.EOLN)
      cout<<lex.word().toString();
}

bool  goodLine(Lex &l , int& t){
  while(t == Lex::LBRACK||t == Lex::LPAR ||t == Lex::LT){
    switch(t){
    case Lex::LBRACK:
      doA(l,t);    
      if(t != Lex::RBRACK){
	cout<<endl<<"Error on line, Expected: ]"<<endl;
	return false;
      }
      break;
    case Lex::LPAR:
      doA(l,t);
      if(t != Lex::RPAR){
	cout<<endl<<"Error on line, Expected: )"<<endl;
	return false;
      }
      break;
    case Lex::LT:
      doA(l,t);
      if(t != Lex::GT){
	cout<<endl<<"Error on line, Expected: >"<<endl;
	return false;
      }
      break;
    default:
      break;
    }
    next(l,t);
  }
  
  return true;
}

bool doA(Lex&l,int &t){
  next(l,t);
  if(t == Lex::LBRACK||t == Lex::LPAR || t == Lex::LT){
    return goodLine(l,t);
  }
  return true;
}

/*

Setting '()<>[]'
         ()<>[]
Syntactically correct

Setting '<<>>'
         <<>>
Syntactically correct

Setting '<<>(()[])>'
         <<>(()[])>
Syntactically correct

Setting '<<>(()[t])>'
         <<>(()[t
Error on line, Expected: ']'

Setting '<<]]'
         <<]
Error on line, Expected: '>'

Setting '(<>>'
         (<>>
Error on line, Expected: ')'

Setting '[[<>()<>))'
         [[<>()<>)
Error on line, Expected: ']'

Setting '<<>(()[])><><>()'
         <<>(()[])><><>()
Syntactically correct
		  
 */
