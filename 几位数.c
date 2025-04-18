
/*思路：用n /=10;temp++; 来计算这个数是几位数（不包括 0）0 的话单独处理一下，
		输入00123等的话long long int等 会自动忽略前面的 0 。
*/
#include<stdio.h>
int main(){

	long long n;
	int temp=0; 
	
	scanf("%lld",&n);
	if (n==0) {
		temp = 1;
		}
	while (n){    
		
		n /=10;
		temp++;
		
	}	
	printf("%d",temp);
	return 0;
}
