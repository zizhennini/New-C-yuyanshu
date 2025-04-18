#include<stdio.h>
int main(){

	int a,b,ones1,ten1,ones2,ten2;
	scanf("%d*%d",&a,&b);
	
	ones1 = a % 10;
	ten1 = (a / 100) % 10;
	ones2 = b / 1000;
	ten2 = (b % 100) / 10;
	int A = (ten1 * 10 + ones1);
	int B = (ones2 * 10 + ten2);
	int sum = (ten1 * 10 + ones1) * (ones2 * 10 + ten2);
	printf("%d*%d=%d",A,B,sum);
	return 0;
}
