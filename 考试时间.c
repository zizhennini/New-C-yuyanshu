/*
任务描述:
小白弟弟参加期末考试，于H1时M1分开始答题，于H2时M2分交卷。假设考试在白天进行，时间采用24小时制。请你算算小白弟弟此次考试用了多少分钟。
输入格式:
空格分隔的4个整数，分别表示H1、M1、H2、M2。
输出格式:
一个整数。
输入样例:
8 30 9 10
输出样例:
40
思路：考试结束的小时数 - 考试前的小时数 * 60 - 结束时间的分钟
*/
#include<stdio.h>
int main(){
	int H1,M1,H2,M2,bad;
	scanf("%d %d %d %d",&H1,&M1,&H2,&M2);
	bad = (H2 - H1) * 60 + M2 - M1;
	printf("%d",bad);
	return 0;
}
