#include<stdio.h>
int main(){
	int week,n;
	scanf("%d %d",&week,&n);
	
	printf("%d",(n+week) % 7);
	return 0;
}
