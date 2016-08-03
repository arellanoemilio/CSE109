#include <stdio.h>
struct Node{
  int x;
  struct Node *left,*right;
};

#define true 1
#define  false 0

void display(struct Node *root);
int inTree(int x, struct Node *root);  
void init(struct Node * n,int a, struct Node *l, struct Node *r);
int main(){
  struct Node root,a,b,c,d,e;
  init(&root,4,&a,&b);
  init(&a,0,NULL,&d);
  init(&b,22,&c,NULL);
  init(&c,18,NULL,&e);
  init(&d,2,NULL,NULL);
  init(&e,21,NULL,NULL);
  
  /*                  root:4
		     /      \
		    a:0      b:22
		   /  \     /   \
		  NL   d:2 c:18 NL
		      / \  /  \
		     NL NL NL  e:21
		              / \
			     NL NL
  */
  printf("Here is the ordered list\n");
  display(&root);
  printf("Here are those values in the subtree with root 22\n");
  display(&b);
  printf(" 5 is %s in the tree\n",inTree(5,&root)?"":"not");
  printf(" 22 is %s in the tree\n",inTree(22,&root)?"":"not");
  return 0;
}

void display(struct Node *root){
  if(root != NULL){
    display(root->left);
    printf("%d\n",root->x);
    display(root->right);
  }
}

int inTree(int x, struct Node *root){
  if(root != NULL){
    if(x == root->x)
      return true;
    else if(x < root->x)
      return inTree(x, root->left);
    else 
      return inTree(x, root->right);
  }
  return false;
}


void init(struct Node * n,int a, struct Node *l, struct Node *r){
  n->x=a;
  n->left=l;
  n->right=r;
}

/*OUTPUT:
Here is the ordered list
0
2
4
18
21
22
Here are those values in the subtree with root 22
18
21
22
 5 is not in the tree
 22 is  in the tree
  
 */
