#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

int main(){
	BST t1, t2, t3;
	//Initialize the BSTs
	initBst(&t1);
	initBst(&t2);
	initBst(&t3);
	
	//Insert the elements from the file to the respective BST
	insertFile(&t1, "number1.txt");
	insertFile(&t2, "number2.txt");
	insertFile(&t3, "number3.txt");
	
	//Opening the file containing the numbers to be searched in the tree
	FILE *fp = fopen("coco.txt", "r");
	
	//Following files for storing the respective results from the BSTs
	FILE *fp1, *fp2, *fp3;
	fp1 = fopen("result1.txt", "w");
	fp2 = fopen("result2.txt", "w");
	fp3 = fopen("result3.txt", "w");
	
	//the below code block stores the number of comparisons done
	
	int *A4, *A5, *A6;
	A4 = (int*)malloc(sizeof(int) * 100);
	A5 = (int*)malloc(sizeof(int) * 100);
	A6 = (int*)malloc(sizeof(int) * 100);
	int i = 0;
	
	
	int num;
	while(fscanf(fp, "%d", &num) == 1 && i < 100){
	  int ele1 = search(t1, num);
	  fprintf(fp1, "%d,", ele1);
	  A4[i] = ele1;
	  
	  int ele2 = search(t2, num);
	  fprintf(fp2, "%d,", ele2);
	  A5[i] = ele2;
	  
	  int ele3 = search(t3, num);
	  fprintf(fp3, "%d,", ele3);
	  A6[i] = ele3;
	}
	
	for(int j = 0; j < 100; j ++){
	  printf("%d\t",A4[j]);
	}
	//inorder(t);
	printf("\n");
	return 0;
}
