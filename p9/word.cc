#include "word.h"

Word::~Word(){
  delete [] wd;
}

Word::Word(){
  copy("");
}

Word::Word(const Word & w){
  copy(w.wd);
}

Word:: Word(const char *ch){
  if(ch == NULL)
    copy("");
  else
    copy(ch);
}
Word:: Word(char ch){
  wd= new char(ch);
  size = 1;
}

void Word::copy(const char * str){
  wd=new char[strlen(str)+1];
  check(wd!=NULL,"Heap overlow");
  strcpy(wd,str);
  size=strlen(wd);
}

void Word::check(bool b, const char * mess){
  if(!b){
    cout<<mess<<endl;
    exit(1);
  }
}

bool operator<(const Word &a,const Word &b){
   return strcmp(a.wd,b.wd)<0;
}

bool operator>(const Word &a,const Word &b){
   return strcmp(a.wd,b.wd)>0;
}

bool operator<=(const Word &a,const Word &b){
   return strcmp(a.wd,b.wd)<=0;
}

bool operator>=(const Word &a,const Word &b){
   return strcmp(a.wd,b.wd)>=0;
}

bool operator==(const Word &a,const Word &b){
   return strcmp(a.wd,b.wd)==0;
}

bool operator!=(const Word &a,const Word &b){
   return strcmp(a.wd,b.wd)!=0;
}

const Word & Word::operator=(const Word & w){
  if(this!=&w){
  copy(w.wd);
  }
  return *this;
}

char & Word:: operator[](int n){
  check(n >= 0 && n < size,"Error: Word: operator []: int out of bounds");
  return wd[n];
}

char Word::  operator[](int n)const{
  check(n >= 0 && n < size,"Error: Word: operator []: int out of bounds");
  return wd[n];
}

const int Word:: length()const{
  return size;
}

char*  Word:: toString()const{
  char* ch;
  ch = new char[size +1];
  int i =0;
  while(i<size){
    ch[i] =wd[i];
    i++;
  }
  ch[size] = '\0';
  return ch;
}

int Word:: toInt(){
  int num = 0;
  for(int i = 0; i <= size; i++){
       switch(wd[size-1- i]){
      case '1': 
	num += (1*(pow(10,i)));
	break;
     case '2': 
       	num += (2*(pow(10,i)));
	break;
     case '3': 
	num += (3*(pow(10,i)));
	break;
     case '4': 
	num += (4*(pow(10,i)));
	break;
     case '5': 
	num += (5*(pow(10,i)));
	break;
     case '6': 
	num += (6*(pow(10,i)));
	break;
     case '7': 
	num += (7*(pow(10,i)));
	break;
     case '8': 
	num += (8*(pow(10,i)));
	break;
     case '9': 
	num += (9*(pow(10,i)));
	break;
     case '0': 
	num += (0*(pow(10,i)));
	break;
       default://check(false,"Error: Word: toInt: string cannot be turned into int");
	break;
    }
       //cout<<num<<endl;
  }
  return num;
}

Word Word:: fromInt(int i){
  Word temp;
  int tempI = i;
  int intLength = 1;
  while(tempI/10 > 0){
    intLength++;
    tempI = tempI / 10;
  }
  char *c =new char[intLength+1];
  //cout<<i<<endl;
  for(int j = 0; j <intLength; j++){
    //problem line, for some reason c[j] is not being set to digit:
    int digit = i/(int(pow(10,intLength-1-j)));
    c[j] = digit + '0';

    i = i%(int(pow(10,intLength-1-j)));
    // cout<<i<<" "<<digit<<" "<<c[j]<<endl;
  }
  c[intLength]='\0';
  temp.copy(c);
  return temp;
}

istream & operator>>(istream &in,Word & w){ 
  char *temp,ch;
  int tempSize,loc;
  tempSize=10;
  temp=new char[tempSize+1];
  Word::check(temp!=NULL,"Heap overflow");
  ch=in.get();
  loc=0;
  while(in.good() && ch!='\n'){
    if(loc==tempSize){
      char *tempA;
      tempA=new char[2*tempSize+1];
      Word::check(tempA!=NULL,"Heap overflow");
      for(int j=0;j<tempSize;j++)
	tempA[j]=temp[j];
      delete[]temp;
      temp=tempA;
      tempSize*=2;
    }
    temp[loc]=ch;
    loc++;
    ch=in.get();
  }
  temp[loc]='\0';
  delete [] w.wd;
  w.wd=temp;
  w.size=strlen(temp);
  return in;
}

ostream & operator<< (ostream &out,const Word &w){
  for(int i = 0; i < w.length(); i++){
    out<<w[i];
  }
  return out;
}
