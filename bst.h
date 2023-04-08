#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef node *BST;

void initBst(BST *t);
void insertBst(BST *t, int k);
void insertFile(BST *t, char *filename);
int search(BST t, int k);
void inorder(BST t);
