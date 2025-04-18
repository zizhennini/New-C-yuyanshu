/*
解题思路：数的大小排序，用冒泡排序就可以了，如果 a > b 那 b 就和 a 交换即 b=a,a=b(要一个中间变量temp即temp = a;a = b;b = temp;)
		  不然就不是交换了。
*/
#include<stdio.h>
int main(){

	int a,b,c,temp;
	scanf("%d %d %d",&a,&b,&c);
	
	if (a > b){
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c){
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c){
		temp = b;
		b = c;
		c = temp;
	}
	printf("%d %d %d",a,b,c);
	return 0;
}
