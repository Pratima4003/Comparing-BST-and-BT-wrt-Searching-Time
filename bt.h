#include<stdio.h>
#include<stdlib.h>

typedef struct b_node{
	int data;
	struct b_node *left, *right;
}b_node;

typedef b_node *BT;

void initBt(BT *bt);
void insertBt(BT *bt, int k);
void insertFileB(BT *bt, char *filename);
int search(BT bt, int k, int *found);
