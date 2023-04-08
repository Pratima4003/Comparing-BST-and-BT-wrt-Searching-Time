#include"bst.h"
#include<stdio.h>
#include<stdlib.h>

//function that is the initialiser of the BST to NULL
void initBst(BST *t){
	*t = NULL;
	return;
}

//function to insert the element into the BST
void insert(BST *t, int k){
  //New node
  node *nn = (node*)malloc(sizeof(node));
  //if the new node is not available
  if(!nn)
    return;
  nn->data = k;
  nn->left = NULL;
  nn->right = NULL;
  //if the tree is empty
  if(*t == NULL){
    *t = nn;
    return;
  }
  
  node*p = *t;
  //q is for the parent element
  node*q = NULL;
  while(p){
    q = p;
    //if the element is already present in the tree, then skip it and return
    if(p->data == k)
      return;
    //if the element is less than the present element then go to the left of the tree
    if(p->data > k)
      p = p->left;
    //if the element is greater than the present tree, then go to the right of the tree
    else
      p = p->right;
  }
  
  //if the element is smaller than the parent, then attach the new node to the left of the parent
  if(k < q->data)
    q->left = nn;
  //else attach to the right of the parent
  else
    q->right = nn;
  return;
}

void insertFile(BST *t, char *filename){
  FILE *fp;
  //open the file with the name given in the argument
  fp = fopen(filename, "r");
  
  //condition if the file does not exist or has no right permissions
  if(!fp)
    return;
  
  int num;
  //to insert the elements from the file to the BST
  while(fscanf(fp, "%d", &num) == 1){
    insert(t, num);
  }
  return;
}

void inorder(BST t){
  if(!t)
    return;
  inorder(t->left);
  printf("%d\t", t->data);
  inorder(t->right);
  return;
}

//Search program to write 
int search(BST t, int k){
  if(!t)
    return -1;
  node*p = t;
  int c = 0;
  while(p){
    if(p->data == k){
      c++;
      break;
    }
    if(p->data > k){
      c++;
      p = p->left;
    }
    else{
      c++;
      p = p->right;
    }
  }
  return c;
}
















