#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void getScores(string names[],int scores[],int &n, int size);
void display(string names[],int scores[],const int n);

int main(){
  const int SIZE=20;
  string names[SIZE];
  int n,scores[SIZE];
  getScores(names,scores,n,SIZE);
  cout<<"The original list\n";
  display(names,scores,n);

  /* optional: remove comments if you wish to
     implement
  sort(names,scores,n);
  cout<<"The sorted list\n";
  display(names,scores,n);
  */
}

void getScores(string names[],int scores[],int &n, int size){
  ifstream inputStream;
  n = 0;
  inputStream.open("lab3.dat");
  if(!inputStream.good()){
    cout<<"could not find file"<<endl;
    exit(1);
  }
  inputStream >> names[n];
  while(inputStream.good() && n < size){
    inputStream >> scores[n++];
    inputStream >> names[n];
  }
  if(inputStream.good()){
    cout<<"Error: There are more than " <<size<<" names in the file"<<endl;
    exit(1);
  }
}

void display(string names[],int scores[],const int n){
  for(int i = 0; i < n; i++)
    cout<<names[i]<<" "<<scores[i]<<endl;
}
