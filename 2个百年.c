/*
输入格式:
一个整数N(N>=2000)，代表某个年度数。
输出格式:
两个整数，以空格分隔，分别代表建党周年数和建国周年数。
输入样例: 2049
输出样例: 128 100

*/
#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	if (N>=2000){
		printf("%d %d",N-1921,N-1949);
	}else{
		printf("输入一个大于等于2000的年份数");
	}
	return 0;
}
