#include "table.h"

Table::~Table(){
   for(int i = 0; i < size; i++){
    table[i] = NULL;
  }
  delete[] table;
}

Table::Table(int s){
  while(!isprime(s)){
    s++;
    }
  size = s;
  table = new Rek*[size];
  for(int i = 0; i < size; i++){
    table[i]=NULL;
  }
}

int & Table::operator[](const Key &k){
  // cout<<"start int [] with key="<<k<<endl;
  check(k!=NULL,"Error: Table: operator []: Key is NULL");
  int hashNum = k.hash()%size;
  Rek *head = table[hashNum];
  if(!inTable(k)){
    table[hashNum] = new Rek(k);
    table[hashNum]->next = head;
    //cout<<"end int [] with key="<<k<<endl;
    return table[hashNum]->data;
  }
  else{
    while(head != NULL){
      if(head->getKey() == k){
	//cout<<"end int [] with key="<<k<<endl;
	return head->data;
      }
      head = head->next;
    }
  }
  //cout<<"end int [] with key="<<k<<endl;
  return head -> data;
}

int Table::operator[](const Key &k)const{
  check(k!=NULL,"Error: Table: operator []: Key is NULL");
  check(inTable(k), "Error: Table: operator []: missing key");
  Rek *temp = table[k.hash()%size];
  while(temp != NULL){
    if(temp->getKey() == k){
      return temp->data;
    }
    temp = temp->next;
  }
  return temp->data;
  }

bool Table:: inTable(const Key &k)const{
  //cout<<"start inTable with k= "<<k<<endl;
  int hashNum = k.hash();
  // cout<<k<<endl;
  int linkList = hashNum %size;
  //cout<<linkList<<endl;
  Rek *head = table[linkList];
  // cout<<head<<endl;
  while(head != NULL){
    //cout<<"inside loop"<<endl;
    if (head->getKey() == k)
       return true;
    //cout<<"after if"<<endl;
    head = head->next; 
  }
   return false;
}

ostream & operator <<(ostream &out,const Table &t){
  double obj = 0;
  double entries = 0;
  out<<"-------------------"<<endl;
  for(int i = 0; i < t.size; i++){
    if(t.table[i] != NULL){
      out<<i<<"\t";
      entries++;
      Rek *head = t.table[i];
      while(head != NULL){
	obj++;
	out<<*head;
	head = head->next;
      }
      out<<endl;
    }
  }
  out<<"-------------------"<<endl;
  out<<"There are "<<entries<<" entries, requiring and average of "<<obj/entries<<" looks to find"<<endl;
  return out<<"-------------------"<<endl;
}

void Table::check(bool flag, string mess)const{
  if(!flag){
    cout<< mess<<endl;
    exit(1);
  }
}


bool Table:: isprime(int i){
  for(int j = 2; j < i; j++)
    if(i%j == 0)
      return false;
  return true;
}


