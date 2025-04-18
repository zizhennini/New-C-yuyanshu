#include<stdio.h>
int main(){

	int score;
	
	scanf("%d",&score);
	if (score <= 100){
		printf("A");
	}else if (score < 90){
		printf("B");
	}else if (score < 80){
		printf("C");
	}else if (score < 70){
		printf("D");
	}else if (0 < score && score < 60){
		printf("E");	
	}else{
		printf("X");
	}

	return 0;
}
