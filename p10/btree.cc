#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
  private:
    int key;
  public:
    double data;
    Node *child[2];
    static const int L=0, R=1;
    Node(int k, double d=0, Node *left = NULL, Node * right = NULL);
    Node (const Node &n);
    int getKey()const;
    friend ostream &operator <<(ostream &out, const Node &n);
};
Node::Node(int k, double d, Node *left, Node *right):key(k),data(d)
{
    child[L] = left;
    child[R] = right;
}
int Node:: getKey() const
{
    return key;
}
ostream &operator <<(ostream &out, const Node &n)
{
    out << "[" << n.key<<"," << n.data << "]";
    return out;
}
class Tree
{
  private:
    Node *root;
  public:
    Tree();
    Tree(const Tree &t);
    const Tree &operator = (const Tree &t);
    friend ostream & operator <<(ostream &out, const Tree &t);
    bool inTree(int k) const;
    double & operator [](int k);
    double & operator [](int k) const;
    ~Tree();
  private:
    Node * locate(int k, Node *rt) const;
    ostream & display(ostream &out, Node *r, int dir=Node::L)const;
    void add(int k, Node *&r);
    void kill(Node *&rt);
    void copy(Node *rt, Node *&newRt);
    void check(bool good, const char * msg);
};
int main()
{
    Tree t, t2;
    t[80] = 60.5;
    t[50] = 45.6;
    t[100] = 45.6;
    t[90] = 35.3;
    t[125] = 50;
    t[65] = 134;
    cout << "Tree t: " << t << endl;
    if(t.inTree(600))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
Tree::~Tree()
{
    kill(root);
}
void Tree::kill(Node *&rt)
{
    if(rt!=NULL){
        kill(rt->child[Node::L]);
        kill(rt->child[Node::R]);
        delete rt;
        rt = NULL;
    }
}

Tree::Tree()
{
    root = NULL;
}
double & Tree::operator[](int k)
{
    if(!inTree(k)){
        add(k,root);
    }
    return locate(k,root)->data;
}
void Tree::add(int k, Node *&r)
{
    if(r == NULL){
        r = new Node(k);
    }
    else
        if(k < r->getKey())
            add(k,r->child[Node::L]);
        else
            add(k,r->child[Node::R]);
}
bool Tree::inTree(int k)const
{
    return locate(k,root) != NULL;
}

Node * Tree::locate(int k, Node *rt) const
{
    if(rt==NULL)
        return rt;
    if(k==rt->getKey())
        return rt;
    if(k < rt->getKey())
        return locate(k,rt->child[Node::L]);
    else
        return locate(k,rt->child[Node::R]);
}
ostream &operator << (ostream &out, const Tree &t)
{
    return t.display(out,t.root);
}
ostream& Tree::display(ostream &out, Node *r, int dir)const
{
    if(r!=NULL){
        display(out,r->child[dir],dir);
        out <<*r<< endl;
        display(out,r->child[1-dir],dir);
    }
    return out;
}










