#ifndef TREE_T
#define TREE_T
#include <iostream>
#include "node.t" 
using namespace std;
/*this template allows the client to have a sorted binary tree of nodes with a key and data of any type*/
template<class X,class Y>
class Tree{
private:
  Node<X,Y> *root;
public:
//post-Condition: creates an empty string containing nodes of <X,Y> types
  Tree();
//post-condition: creates a deep copie of Tree t 
  Tree(const Tree &t);
//post-Condition: copies Tree t and returns the new Tree
  const Tree<X,Y> & operator = (const Tree &t);
// post-Conditionretruns true if Key is in the tree, else returns false
  bool inTree(X k)const;
//Pre-Condition: k is in the tree
//post-condition: returns the memory address of the data of  k 
  Y & operator [](X k);
//Pre-Condition: k is in the tree
//post-condition: returns the memory address of the data of  k 
  Y & operator [](X k)const;
//post-condition: deletes instance of Tree
  ~Tree();
//postcontition: prints out the tree and all of its members in assending order
  template<class S, class U>
  friend ostream & operator <<(ostream &out, const Tree<S,U> &t);
private:
  Node<X,Y> *locate(X k, Node<X,Y> *rt)const;
  void add(X k, Node<X,Y> *&r);
  void kill(Node<X,Y> *&r);
  void copy(Node<X,Y> *rt, Node<X,Y> *&newRt);
  void check(bool good, const char *msg);
  ostream & display(ostream &out, Node<X,Y> *r, int dir = Node<X,Y>::L)const;
};


template<class X,class Y>
void Tree<X,Y>:: check(bool flag,const char* msg){
  if(!flag){
    cout<<msg<<endl;
    exit(0);
  }
}   

template<class X, class Y>
Tree<X,Y>::~Tree(){
  kill(root);
}

template<class X, class Y>
void Tree<X,Y>::kill(Node<X,Y> *&rt){
  if(rt != NULL){
    kill(rt->child[Node<X,Y>::L]);
    kill(rt->child[Node<X,Y>::R]);
    delete rt;
    rt = NULL;
  }
}

template<class X, class Y>
Tree<X,Y>::Tree(){
  root = NULL;
}

template<class X, class Y>
Tree<X,Y>::Tree(const Tree<X,Y> &t){
  copy(t.root,root);
}

template<class X, class Y>
const Tree<X,Y> & Tree<X,Y>:: operator = (const Tree &t){
  copy(t.root,root);
  return *this;
}

template<class X, class Y>
void Tree<X,Y>::copy(Node<X,Y> *rt, Node<X,Y> *&newRt){
  if(rt != NULL){
    newRt = new Node<X,Y>(rt->getKey(), rt->data);
    copy(rt->child[Node<X,Y>::L],newRt->child[Node<X,Y>::L]);
    copy(rt->child[Node<X,Y>::R],newRt->child[Node<X,Y>::R]);
  }
}

template<class X, class Y>
bool Tree<X,Y>:: inTree(X k)const{
     return locate(k, root) != NULL;
}

template<class X,class Y>
Node<X,Y> *Tree<X,Y>::locate(X k, Node<X,Y> *rt)const{
  if(rt == NULL)
    return rt;
  if(k == rt->getKey())
    return rt;
  if(k < rt->getKey())
    return locate(k, rt->child[Node<X,Y>::L]);
  else
    return locate(k, rt->child[Node<X,Y>::R]);
}

template<class X, class Y>
Y & Tree<X,Y>:: operator [](X k){
  if(!inTree(k))
    add(k,root);
  return locate(k,root)->data;
}

template<class X, class Y>
Y & Tree<X,Y>:: operator [](X k)const{
  //check(inTable(k),"Error: Key not in table");
  return locate(k,root)->data;
}


template<class X, class Y>
void Tree<X,Y>:: add(X k, Node<X,Y> *&r){
  //check(!inTable(k),"Error: Key is already in table");
  if(r==NULL)
    r = new Node<X,Y>(k);
  else
    if(k < r->getKey())
      add(k, r->child[Node<X,Y>::L]);
    else
      add(k, r->child[Node<X,Y>::R]);
}

template<class X,class Y>
ostream & operator <<(ostream &out, const Tree<X,Y> &t){
 // check(t.root != NULL, "Error: tree is empty");
  return t.display(out,t.root);
}

template<class X,class Y>
ostream & Tree<X,Y>:: display(ostream &out, Node<X,Y> *r, int dir)const{
  if(r != NULL){
    display(out,r->child[dir],dir);
    out <<*r<< endl;
    display(out,r->child[1-dir],dir);
  }
  return out;
}


#endif