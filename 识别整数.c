/*
从键盘输入一串字符(直到字符’.’为止)，表示一个非负整数，数字之间被混进了其它字符，请正确输出该整数。
如果不包含数字，输出0。
输入样例:
abc12d3e4x.
输出样例:
1234
输入样例:
#0%01X23*4.
输出样例:
1234

思路：  主要是用语句 result = result * 10 + num;把每次取到的数字左移一位（其实就是每次循环增大一位数，直到循环结束）
		这样的话输入#0%01X23*4.等等就不会输出001234的情况。
*/
#include<stdio.h>
int main() {


	char ch;
	int m = 0;
	int result = 0;
	
	while ((ch = getchar()) != '.') {
		if ('0' <= ch && ch <= '9') {
			int num = ch - '0';
			result = result * 10 + num;
			m = 1;

		}
	}
	if (m) {
		printf("%d", result);
	}else{
		printf("0");
	}

	return 0;
}
