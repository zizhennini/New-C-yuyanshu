#include<stdio.h>
int main(){

	int n;
	scanf("%d",&n);
	if (n<2){
		printf("NO");
	}else{
	
	int flag=1;
	for (int i=2;i<n;i++){
		if (n % i==0){
			printf("NO");
			flag=0;
			break;
			}
		}
		if (flag){	
			printf("YES");
		}
	}
	
	return 0;
}
