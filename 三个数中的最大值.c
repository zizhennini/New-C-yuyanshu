/*
三个数中的最大值
任务描述:
利用关系运算和条件运算，编程输入3个整数，输出它们中的最大值。

思路：先把最大值随意给一个数，然后与另外两个数比较若另外两个数都没有比它大，那ta就是最大的，如果有比它大的数那最大值就比它大的数了。
*/
#include<stdio.h>
int main(){
	
	int a,b,c,max;
	scanf("%d %d %d",&a,&b,&c);
	max = a;
	if (b > a){
		max = b;
	}
	if (c > a){
		max = c;
	}
	
	printf("%d",max);
	
	return 0;
}
