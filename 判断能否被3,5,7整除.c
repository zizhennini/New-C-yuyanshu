#include<stdio.h>
int main(){

	int n;
	
	scanf("%d",&n);
	
	if (n % 3==0 && n % 5==0 && n % 7==0){
		printf("3 5 7");
	}else{
		if (n % 3!=0 && n % 5==0 && n % 7==0){
			printf("5 7");
		}else if (n % 3==0 && n % 5!=0 && n % 7==0){
			printf("3 7");
		}else if (n % 3==0 && n % 5==0 && n % 7!=0){
			printf("3 5");
		}else{
			printf("n");
		}
	}
	
	return 0;
}
