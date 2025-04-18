/*
鸡兔同笼
任务描述:
中国古代《孙子算经》中记载有趣的“鸡兔同笼”问题：“雉兔同笼，上有三十五头，下有九十四足，问雉兔各几何?”
请仿照上例编程输入一组可能的头数量和脚数量，分别输出鸡兔各多少只。
（提示，可能的数据有：头35脚94、头88脚244、头100脚200、头80脚240、等等）。

解题思路：数学方法设鸡为X只，鸭为Y只，有 1.X + Y = 35，2. 2X + 4Y = 94，2 式 - 1 式 乘 2 得 2Y = 24 ，对于头88脚244这样的也一样 
*/
#include<stdio.h>
int main(){
	int head,foot,chicken,duck;
	scanf("%d %d",&head,&foot);
	chicken = (foot - head * 2) / 2;
	duck = head - chicken;
	printf("%d %d",duck,chicken);
	return 0;
}
