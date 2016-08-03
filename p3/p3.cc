/*
  Emilio Arellano
  Program 3
 */

#include <iostream>
#include <cstdlib>
using namespace std;
/*
this class stors two values and performs diferent opereations with the values and then stores the 
in the acumulator of the CPU
 */
class ALU{

private:
  int register1;
  int register2;
  int accu;

public:
  const static int ADD = 0;
  const static int SUB = 1; 
  const static int MUL = 2; 
  const static int DIV = 3;
  const static int MOD = 4;

private:

public:
  /*
    no arg construction
  */
  ALU();
  
  /*
    copy consturctor
  */
  ALU(const ALU & r);
  
  /*
    one arg constructor, it sorts the arg into the first register and then sets the second register and
 the acumulator to zero. 
   */
  ALU(int i);
  
  /*
    two arg constuctos, sets the first registrer to the first agument
    and the second register to the second constructor while the 
    accumulator is kept with trash
   */
  ALU(int i, int j);

  /*
    This method takes in an operation and stors the value obtained
    from the operation into the accumulator
   */
  ALU & op(int f);
  
  /*
    sets the value of register 1 to i
  */
  ALU & set1(int i);

  /*
    sets the value of register 2 to i
  */
  ALU & set2(int i);

  /*
    Returns the value of the first register
   */
  int get1();
 
  /*
    returns the valure of the second register
  */
  int get2();

  /*
    returns the valure of the accumulator
  */
  int acc();

  /*
    override the << operator to print out the values of the ALU
   */
  friend ostream & operator << (ostream & out, const ALU & a);

};

/*
  prompts user to enter value 1 - 5 
 */
int getChoice();

/*
  tests the functionality of the the class ALU
 */
void test();

int main(){
  ALU a(2,0);
  switch(getChoice()){
  case 1: test(); break;
  case 2: a.op(a.DIV); break;
  case 3: a.op(a.MOD); break;
  case 4: a.op(5); break;
  case 5: a.op(-1); break;
  } 
  return 1;
}

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

int getChoice(){
  char ch;
  do{
    cout<<"Enter a digit from 1 to 5, depending on which of\n"
	<<"the five tests you wish to run- ";
    cin>>ch;
    if(ch<'1' || ch>'5')
      cout<<"Bad entry; please try again\n";
  }while(ch<'1' || ch>'5');
  return ch-'0';
}

void test(){
  ALU a,b(2),c(3,4),d(c);
  a.set1(23).set2(25);
  cout<<"For the next four lines, the accumulator is not defined\n"
      <<"and contains grabage\n";
  cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
  cout<<"Expect 48: "<<a.op(a.ADD).acc()<<endl;
  cout<<"Expect -2: "<<a.op(a.SUB).acc()<<endl;
  cout<<"Expect 575: "<<a.op(ALU::MUL).acc()<<endl;
  a.set1(27).set2(5);
  cout<<"Expect 5: "<<a.op(a.DIV).acc()<<endl;
  cout<<"Expect 2: "<<a.op(a.MOD).acc()<<endl;
  cout<<"Expect {acc: 2, reg1: 27, reg2: 5}: "<<a<<endl;
  cout<<"Expect 27, 5: "<<a.get1()<<", "<<a.get2()<<endl;
}

/*SAMPLE RUNS OF p3

Enter a digit from 1 to 5, depending on which of
the five tests you wish to run- 1
For the next four lines, the accumulator is not defined
and contains grabage
{acc: 4197132, reg1: 23, reg2: 25}
{acc: 0, reg1: 2, reg2: 0}
{acc: 1936028704, reg1: 3, reg2: 4}
{acc: 1936028704, reg1: 3, reg2: 4}
Expect 48: 48
Expect -2: -2
Expect 575: 575
Expect 5: 5
Expect 2: 2
Expect {acc: 2, reg1: 27, reg2: 5}: {acc: 2, reg1: 27, reg2: 5}
Expect 27, 5: 27, 5

Enter a digit from 1 to 5, depending on which of
the five tests you wish to run- 2
Error: Division by zero

Enter a digit from 1 to 5, depending on which of
the five tests you wish to run- 3
Error: Mod by zero

Enter a digit from 1 to 5, depending on which of
the five tests you wish to run- 4
Error: op parameter out of range

Enter a digit from 1 to 5, depending on which of
the five tests you wish to run- 5
Error: op parameter out of range
 */
