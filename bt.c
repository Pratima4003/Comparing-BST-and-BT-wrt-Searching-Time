#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"bt.h"

#define EVEN 0
#define ODD 1

/*toss function to generate a random number
  which will decide where to attach the element 
  from the file to the binary tree, 
  so that it will be just a bianry tree 
  without any specific pattern or rules like Binary Search Tree*/

int toss(){
	int number;
	srand(time(NULL));
	number = rand() % 50;
	if(number % 2 == 0)
		return EVEN;
	else
		return ODD;
}

/********************************************************************/

void initBt(BT *bt){
	*bt = NULL;
	return;
}

void insertBt(BT *bt, int k){
	
	//New node
	b_node *nn = (b_node*)malloc(sizeof(b_node));
	if(!nn)
		return;
	nn->data = k;
	nn->left = NULL;
	nn->right = NULL;

	//If the tree is empty
	if(*bt == NULL){
		*bt = nn;
		return;
	}

	b_node*p = *bt;
	//q pointer keeps the track of the previous,i.e. parent node
	b_node*q = NULL;
	while(p){
		q = p;
		//toss function decides whether to go left or right of tree
		int n = toss();
		if(n == EVEN)
		  p = p->left;
		else
		  p = p->right;
	}
	//Similarly toss decides whether to attach newnode to the left or right
	int a = toss();
	if(a == EVEN)
	  q->left = nn;
	else
	  q->right = nn;
	return;
}

void insertFileB(BT *bt, char *filename){
	FILE *fp;
	//Open the file with the name give as parameter
	fp = fopen(filename, "r");

	//condition if the file does not exist or has no right permission
	if(!fp)
	  return;
	int num;
	//To insert an element from the file to the BT
	while(fscanf(fp, "%d", &num) == 1){
		insertBt(bt, num);
	}
	return;
}

int search(BT bt, int k, int *found){
  //If the Binary tree is not present
  if(bt == NULL)
    return 0;
  
  //If the element is present return the count
  if(bt->data == k){
    *found = 1;
    return 1;
  }
  
  int count = search(bt->left, k, found);
  if(*found)
    return (1 + count);
  return (count + 1 + search(bt->right, k, found));  
}
