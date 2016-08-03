#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void check(bool flag,string messege1,string messege2 = "",string messege3 = "");
void check(bool flag,string messege1);

//void getInt(int i);

int main(){
  ofstream output;
  int n;
  // double x;
  //char ch;
  //bool yes;
  string fileName;
  ifstream input;
  cout<<"Enter a name for the output file- ";
  cin>>fileName;
  output.open(fileName.c_str());
  check(output.good(),"Failure to open the file '",fileName,"'");
  //*If you get the above working, uncomment this section and continue
  input.open("input.txt");
  // check(input.good(),"Failure to open 'input.txt'");
  input>>n;
  while(input.good()){
    output<<n;
    input>>n;
  }
  /*  
  cout<<"Enter an int- ";
  cin>>n;
  check(cin.good(),"'cin' has been disabled");
  cout<<"You entered the int "<<n<<endl;
  getInt(n);
  cout<<"You entered "<<n<<endl;
  getInt(n,2,10);
  cout<<"You entered "<<n<<endl;
  yes=getYorN(ch);
  cout<<"You entered '"<<ch<<"'\n";
  if(yes)
     cout<<"This means yes\n";
  else
    cout<<"This means no\n";
  x=0;
  //getBool(yes);
  cout<<"You entered the bool "<<yes<<endl;
  //getDouble(x);
  cout<<"You entered the double "<<x<<endl;*/
}

void check(bool flag,string messege1,string messege2,string messege3){
 if(flag){
    return;
  }
  else
    cerr<<messege1<<messege2<<messege3<<endl;
 exit(0);
}
void check(bool flag,string messege1){
  if(flag){
    return;
  }
  else
    cerr<<messege1<<endl;
  exit(0);
}
/*
void getInt(int i){
  string empty ="";
  cout<<"Please enter an int: "<<endl;
  cin>>i;
  while(!cin.good()){
    cin.clear();
    getline(cin,empty);
    cout<<"Try again, please enter an int: "<<endl;
    cin>>i;
  }
 }*/
