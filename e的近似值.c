/*
e的近似值
任务描述:
编写程序，输入一个较小的实数deta，利用e=1+1/1!+1/2!+1/3!+⋯+1/n!计算e的近似值，
直到最后一项的绝对值小于deta时为止，输出此时e的近似值。
输入格式:
一个较小的实数deta（deta<0.01）。
输出格式:
题目要求的近似值，保留10位小数。
输入样例:
0.0001
输出样例:
2.7182787698

解题思路：	e 最开始的值为 1，然后加上 1 除以 1到 n 的阶乘；
			主要是要处理1 除以 1到 n 的阶乘，最后比较一下 1 除第 n 项的绝对值是否小于deta就可以了。
			用while 处理（用 temp *= i;i++;来算阶乘，用 term = 1.0 / temp;来算每项的值，然后累加的 e 上，
			当term的绝对值小于deta是循环结束）
*/

#include<stdio.h>
#include<math.h>

int main() {

	double deta;
	double e = 1;				
	double term = 1;				

	scanf("%lf", &deta);
	
	int i = 1;
	int temp = 1;


	while (deta < fabs(term)) {
		temp *= i;
		term = 1.0 / temp;
		e += term;
		i++;
	}
	printf("%.10lf", e);

	return 0;
}
