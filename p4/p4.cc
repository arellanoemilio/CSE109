#include "chip.h"  //chip.h includes mem.h and alu.h

/* function factor() forces the user to enter a positive int and
then uses the "chip" to compute the prime factors of the number. For
example, if the user enters 24, the function would print out 2,2,3
All movement of data and all arithmetic operations must be
accomplished with Chip methods. This tests the functionality of
the class Chip
*/
void factor();

void getInt(int &n); //force user to enter an int > 0
void writeFactors(int n);
void testChip();
void testMemory();

int main(){
  testMemory();
  testChip();
  //test for crashing memory - undefined
  Memory a;
  cout<<a.get()<<endl;
  return 0;
}

  /*Sample run:
    Expect 2: 2
    Expect 2: 2
    Expect 20: 20
    Expect 343: 343
    Expect accum==686: {acc: 686, reg1: 343, reg2: 343}
    Accumulator (expect 17): {acc: 17, reg1: 20, reg2: 3}
    Accumulator (expect 529): 529
    Enter a positive int: 28
    The factors of 28 are:
     2 2 7
     Error[Memory]: undefined memory
  */

void testChip(){
  Chip a(2,5);
  a.op(a.ADD);  // accum has 7
  a.push().push().push();  //three copies of 7 pushed
  a.top(-1).pop().top(-2).op(a.MUL); //put top in reg1, discard top,
  //put top in reg2, multiply to get 49
  a.pop();   //get rid of top
  a.push().pop(-1).pop(-2).op(a.MUL);  //push 49, pop to reg1, pop the
				       //7 to reg2, multiply
  cout<<"Expect 343: "<<a.acc()<<endl;
  a.store(1).load1(1).load2(1).op(a.ADD); //put 343 in mem[1],
  //load memroy to reg1 and reg2, add
  cout<<"Expect accum==686: "<<a<<endl;

  a.set1(20).set2(3).op(a.ADD);
  a.push().pop(30);
  a.op(a.SUB);
  cout<<"Accumulator (expect 17): "<<a<<endl;
  a.load1(30).load2(30);
  a.op(a.MUL);
  cout<<"Accumulator (expect 529): "<<a.acc()<<endl;

  factor();
}

void testMemory(){
  Memory a,b(2),c(2);
  cout<<"Expect 2: "<<b.get()<<endl;
  cout<<"Expect 2: "<<c.get()<<endl;
  /*THE NEXT LINE SHOULD CRASH, BECAUSE a IS UNDEFINED
  cout<<a.get();
  */
  a.set(20);
  cout<<"Expect 20: "<<a.get()<<endl;
}

void factor(){
  int n;
  getInt(n);
  cout<<"The factors of "<<n<<" are: \n";
  writeFactors(n);
}

void getInt(int &n){
  do{
    cout<<"Enter a positive int: ";
    cin>>n;
    if(n<=0)
      cout<<"You must enter an int > 0; please try again";
  }while(n<=0);
}

void writeFactors(int n){
  Chip a(n);
  a.op(a.ADD);  //accum has n
  a.store(1);  //n in location 1
  a.set1(2);   //2 in reg 1
  a.op(a.ADD);  //accum has 2
  a.store(2); //divisor
  a.load1(1).load2(2);    //load n, 2 into registers 1 and 2
  while(a.get2()<=a.get1()){ //so long as divisor is <= n
    a.op(a.MOD);
    if(a.acc()==0){//n evenly divided by divisor
      a.op(a.DIV);   //divide
      a.store(1);   // replace n with n / divisor
      cout<<" "<<a.get2();
    }
    else{//increment divisor by 1
      a.load1(2).set2(1).op(a.ADD);
      a.store(2);
    }
    a.load1(1).load2(2);
  }
  cout<<endl;
}
      
