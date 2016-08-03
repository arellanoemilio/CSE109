#include <iostream>
#include <cstdlib>
using namespace std;
#include "node.t"
#include "tree.t"
int main()
{ string x[]={"one","two","three","four","five","six"};
  int y[]={12, 122, -9, 87,3, 45};
  Node<int,double> a(2,2.3), b(3,1.4), c(8,1.1,&a,&b);
  cout<<c<<" "<<*c.child[0]<<" "<<*c.child[1]<<endl;
  Tree<string,int> si;
  Tree<int,string> is;
  for(int j=0;j<6;j++){
    si[x[j]]=y[j];
    is[y[j]]=x[j];
  }
  cout<<"The tree 'si': \n"<<si<<endl;
  cout<<"The tree 'is': \n"<<is<<endl;
  Tree<string,int> siCopy(si);
  siCopy["fifty"]=42;
  cout<<"The copied tree:\n"<<si<<endl;
  cout<<"The copy:\n"<<siCopy<<endl;
}
/* OUTPUT
  [8,1.1] [2,2.3] [3,1.4]
  The tree 'si':
  [five,3]
  [four,87]
  [one,12]
  [six,45]
  [three,-9]
  [two,122]

  The tree 'is':
  [-9,three]
  [3,five]
  [12,one]
  [45,six]
  [87,four]
  [122,two]

  The copied tree:
  [five,3]
  [four,87]
  [one,12]
  [six,45]
  [three,-9]
  [two,122]

  The copy:
  [fifty,42]
  [five,3]
  [four,87]
  [one,12]
  [six,45]
  [three,-9]
  [two,122]

  
 */
