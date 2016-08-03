#ifndef NODE_T
#define NODE_T
#include <iostream>
using namespace std;

/*this is a emplate that allows the client to store a key and data for that key of any type*/ 

template<class X, class Y>
class Node{
  X key;
  Node();
public:
//the data of the node
  Y data;
//these are the childre of the node
  Node<X,Y> *child[2];
//L stands for the L child of children R is the right child of children
  static const int L = 0, R = 1;
//post condition: constructs a node with key k, data d, Left child left, and right child right
  Node(X k, Y d=Y(), Node<X,Y> *left = NULL, Node<X,Y> *right = NULL);
//post Contidion: constructs a nody coping the node n
  Node(const Node<X,Y> &n);
//post condition: returns the key of the node
  X getKey()const;
//post condition: prints out the key and data of the node
  template<class S, class U>
  friend ostream &operator << (ostream & out, const Node<S,U> &n);
};

template<class X, class Y>
Node<X,Y>:: Node(X k, Y d, Node<X,Y> *left, Node<X,Y> *right):key(k), data(d){
  child[L] = left;
  child[R] = right;
}

template<class X, class Y>
Node<X,Y>:: Node(const Node<X,Y> &n):key(n.key),data(n.data){
  child[L] = new Node<X,Y>(n.child[L]);
  child[R] = new Node<X,Y>(n.child[R]);
}

template<class X, class Y>
X  Node<X,Y>:: getKey()const{
   return  key;
}

template<class X, class Y>
ostream & operator << (ostream &out, Node<X,Y> & n){
  out << "[" << n.getKey()<<"," << n.data << "]";
  return out;
}
#endif