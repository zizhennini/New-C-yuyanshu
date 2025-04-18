#include<stdio.h>
int main(){

	int n,sum=0;
	
	
	while (1){			// 题目没有说求和的结束条件是什么，这里以 0 为结束循环的条件
		
		scanf("%d",&n);
		if (n==0){
			break;
		}
		
		sum +=n;
		
	}
	printf("%d",sum);
	return 0;
}
