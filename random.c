#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	int i, j, k;
	//int lower = 0, upper = 1;
	srand(time(NULL));
	//number  = rand() % 50; //for only one number till 50
	//number = (rand() % (upper - lower + 1)) + lower; //for range of numbers
	
	//open file for writing
	FILE *fp1, *fp2, *fp3;
	
	fp1 = fopen("number1.txt", "w");
	fp2 = fopen("number2.txt", "w");
	fp3 = fopen("number3.txt", "w");

	for(i = 0; i < 1000; i++){
		int number1 = (rand() % 50000) + 1;
		//printf("%d\t", number);
		
		//write the number to the file
		fprintf(fp1, "%d\t", number1);
	}

	for(j = 0; j < 10000; j++){
		int number2 = (rand() % 50000) + 1;
		fprintf(fp2, "%d\t", number2);
	}

	for(k = 0; k < 100000; k++){
		int number3 = (rand() % 50000) + 1;
		fprintf(fp3, "%d\t", number3);
	}

	//following block of code is for 100 random numbers to be searched in the above files using BST and BT
	FILE *fp4;
	fp4 = fopen("coco.txt", "w");
	
	for(int s = 0; s < 100; s++){
	  int num = (rand() % 50000) + 1;
	  fprintf(fp4, "%d\t", num);
	}
	
	//close the file
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	
	printf("DONE!!\n");
	printf("\n");
	return 0;
}
