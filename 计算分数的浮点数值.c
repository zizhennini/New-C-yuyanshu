#include<stdio.h>
int main(){
	
	int a,b;
	scanf("%d %d",&a,&b);
	double m = (double)a / (double)b;   // 主要是注意类型转换
	printf("%.9lf",m); 
	return 0;
}
