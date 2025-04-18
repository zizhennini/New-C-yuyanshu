#include<stdio.h>
int main(){
	
	int weight,weight_min;
	
	scanf("%d",&weight);
	
	weight_min = (weight / 100) * 10 + weight % 10;   // 取百位和个位的数，然后把它们拼接起来
	
	printf("%d",weight_min);
	
	return 0;
}
