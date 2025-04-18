#include<stdio.h>
int main(){
	
	int a1,a2,n,an;
	scanf("%d %d %d",&a1,&a2,&n);
	an = a1 + (n - 1) * (a2 - a1);
	printf("%d",an); 
	return 0;
}
// 等差数列 第N项公式 an = a1 + (n-1) * d;