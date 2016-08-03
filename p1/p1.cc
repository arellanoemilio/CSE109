#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

/*Checks if flag is true or false.
  pre-conditions:messege1, messege2 and messege3 are not null
  post-condition: if flag is true nothing happens else prints out the three strings and ends program
 */
void check(bool flag,string messege1,string messege2,string messege3);

/*Checks if flag is true or false.                                                                                                                                                                             
  pre-conditions:messege1 is not null                                                                                                                                                    
  post-condition: if flag is true nothing happens else prints out messege1 and ends program                                                                                                             
*/
void check(bool flag,string messege1);

/*Asks user for an int until it recives one
  pre-condition: n is an integer and passed by reference
  post-condition: value of n is changed to the int entered
 */
void getInt(int &n);

/*Askes for the used for an in between two other ints until the int is between the two other numbers
  pre-condition: n is an int passed by reference, low is a smaller int than high
  post-condition: n is assigned the value of the int entered
 */
void getInt(int &n, int low, int high);

/*prompts user to enter y Y n or N until user enters one of the chars
  pre-condition: ch is a char passed by reference
  post-condition:retuns true if input is y or Y otherwise returns false if input is n or N
 */
bool getYorN(char &ch);

/*promts user for an int for it to be transformed into a bool
  pre-condition:b is a bool passed by reference
  post-condition: return true if input is not 0, retun false if input is 0
 */
void getBool(bool &b);

/*propmts user to enter a double until he does
  pre-condition: d is a double passed byu reference
  post-condition: d is assinged the double entered
 */
void getDouble(double &d);

int main(){
  ofstream output;
  int n;
  double x;
  char ch;
  bool yes;
  string fileName;
  ifstream input;
  cout<<"Enter a name for the output file- ";
  cin>>fileName;
  output.open(fileName.c_str());
  check(output.good(),"Failure to open the file '",fileName,"'");
  input.open("input.txt");
  check(input.good(),"Failure to open 'input.txt'");
  input>>n;
  while(input.good()){
    output<<n;
    input>>n;
  }
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
  getBool(yes);
  cout<<"You entered the bool "<<yes<<endl;
  getDouble(x);
  cout<<"You entered the double "<<x<<endl;
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

void getInt(int &n){                                                                               
  string empty = "";                                                                               
  cout<<"Please enter an int: "<<endl;                                                             
  cin>>n;                                                                                          
  while(!cin.good()){                                                                              
    cin.clear();                                                                                  
    getline(cin,empty);                                                                            
    cout<<"Try again, please enter an int: "<<endl;                                                
    cin>>n;                                                                                        
  }                                                                                                
}

void getInt(int &n, int low,int high){
  string empty = "";
  bool end = false;
  cout<< "Please enter an int in the range["<<low<<","<<high<<"]"<<endl;
  cin>>n;
  if(n>low &&  n<high)
    end = true;
  while(!end){
    if(!cin.good()){
      cin.clear();
      getline(cin,empty);
      cout<<"Bad input, try again"<<endl;
      cin>>n;
    }else{
      cout<<"int entered is nor in ["<<low<<","<<high<<"]"<<endl<<"Enter an int"<<endl;
      cin>>n;
    } 
    if(n>low &&  n<high)
      end = true;
  }
}

bool getYorN(char &c){
  cout<<"Enter 'y', 'Y', 'n' or 'N': "<<endl;
  while(true){
    cin >> c;
    if(c == 'y' || c == 'Y')
      return true;
    else if(c == 'n' || c == 'N')
      return false;
    else
      cout<<"You did not enter y, Y, n or N. Try again"<<endl;
  }
}

void getBool(bool &b){
  int n;
  cout<<"Enter a bool, the int 0 for false, any other int for true"<<endl;
  getInt(n);
  b = n;
}

void getDouble(double &d){
  string empty = "";
  cout<<"Enter a double"<<endl;
  cin>>d;
  while(!cin.good()){
    cin.clear();
    getline(cin,empty);
    cout<<"Try again, please enter  double: "<<endl;
    cin>>d;
  }
}
