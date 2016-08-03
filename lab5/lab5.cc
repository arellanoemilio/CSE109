#include "rek.t"

template <class X, class Y>
void show(Rek<X,Y> * hd);

int main(){
  Rek<int,int> *h1;
  h1=new Rek<int,int>(2,3);
  h1->next=new Rek<int,int>(4,5);
  show(h1);

  Rek<double,string> *h2;
  h2=new Rek<double,string>(4.2);
  h2->next=new Rek<double,string>(2.7,"One");
  show(h2);

  Rek<char,string> *h3;
  h3=new Rek<char,string>('a',"The letter 'a'");
  h3->next=new Rek<char,string>('b',"The letter 'b'");
  h3->next->next=new Rek<char,string>('c',"The letter 'c'");
  show(h3);
  h3->next->next->data="THE LETTER 'c'";
  show(h3);
  cout<<"The third key: '"<<h3->next->next->getKey()<<"'\n";
}

/*THE EXPECTED OUTPUT
  -->[2, 3]-->[4, 5]
  -->[4.2, ]-->[2.7, One]
  -->[a, The letter 'a']-->[b, The letter 'b']-->[c, The letter 'c']
  -->[a, The letter 'a']-->[b, The letter 'b']-->[c, THE LETTER 'c']
  The third key: 'c'
 */

template <class X, class Y>
void show(Rek<X,Y> * hd){
  while(hd!=NULL){
    cout<<"-->"<<*hd;
    hd=hd->next;
  }
  cout<<endl;
}
