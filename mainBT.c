#include<stdio.h>
#include<stdlib.h>
#include"bt.h"

int main(){
	BT bt1, bt2, bt3;
	//Initialize the binary trees
	initBt(&bt1);
	initBt(&bt2);
	initBt(&bt3);
	
	//Inserting the numbers to the binary tree
	insertFileB(&bt1, "number1.txt");
	perror("reached till here\n");
	
	insertFileB(&bt2, "number2.txt");
	perror("reached till here\n");
	
	//insertFileB(&bt3, "number3.txt");
	//perror("reached till here\n");
	
	//Opening the file containing the elements to be searched in the tree
	FILE *fp = fopen("coco.txt", "r");
	
	//Following files for storing the respective results from the BSTs
	FILE *fp4, *fp5, *fp6;
	fp4 = fopen("resultB1.txt", "w");
	fp5 = fopen("resultB2.txt", "w");
	perror("reached till here\n");
	
	//fp6 = fopen("resultB3.txt", "w");
	
	//the below code block stores the number of comparisons done in the file as well as array
	int num;
	int found1 = 0, found2 = 0, found3 = 0;
	
	int *A1, *A2, *A3;
	A1 = (int*)malloc(sizeof(int) * 100);
	A2 = (int*)malloc(sizeof(int) * 100);
	A3 = (int*)malloc(sizeof(int) * 100);
	int i = 0;
	
	while(fscanf(fp, "%d", &num) == 1 && i < 100){
	  int ele1 = search(bt1, num, &found1);
	  fprintf(fp4, "%d,", ele1);
	  A1[i] = ele1;
	  
	  int ele2 = search(bt2, num, &found2);
	  fprintf(fp5, "%d,", ele2);
	  A2[i] = ele2;
	  
	  //int ele3 = search(bt3, num, &found3);
	  //fprintf(fp6, "%d\t", ele3);
	  //A3[i] = ele3;
	  i++;
	}
	perror("reached till here\n");
	
	printf("\n");
	return 0;
}
