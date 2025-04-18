/*
解题思路：int temp=n%10;通过这个语句在循环时取最后一位数，取了最后一位数后去掉原来的数用 语句 n /=10 来实现;
		  用语句 sum = sum * 10 + temp;把每次取到的最后一位数左移一位（其实就是每次循环增大一位数，直到循环结束）
*/

#include<stdio.h>
int main(){

	int n,sum=0;
	
	scanf("%d",&n);
	while (n) {
		
		int temp=n%10;
		n /=10;
		sum = sum * 10 + temp;
		
	}
	printf("%d",sum);

	return 0;
}
