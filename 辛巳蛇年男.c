/*
辛巳蛇宝男
任务描述：
2001年01月24日是农历辛巳蛇年的春节(大年初一)，2002年02月11日是辛巳蛇年的除夕。赵中瑞的生日是2002年01月07日，
所以我们称他为“辛巳蛇宝男”，赵中瑞想知道还有谁和他一样是“辛巳蛇宝男”，你帮他找出来。
（不允许用if语句和switch语句）（提示：使用条件运算符 ? : ）
输入格式:
一行中给出一个中华人民共和国的二代身份证号和姓名，中间没有空格。
注意：身份证号倒数第2位若为奇数则为男生，若为偶数则为女生，你知道吗？
输出格式:
若是“辛巳蛇宝男”则输出：YES，否则输出：NO。
为保密，样例中的身份证号前6位统一设为239999。

解题思路：因为身份证号前6位统一设为239999，只需要输入出生日期和身份证后四位，所以这样的格式输入239999%4d%2d%2d%4d%s，
		  %4d限定一下宽度，主要是为了更好的获取输入的出生日期的年月日，然后就是输入姓名了，直接定义一个字符串来接收
		  输入的姓名的话 ，会出现“溢出”问题，所以定义一个长度20的字符串数组来接收输入的姓名，最后用？：来判断一下出
		  生日期在不在范围内以及性别是否为男。
*/
#include<stdio.h>
int main() {
    int year, month, day, code;
    char name[20]; 			

	/* 读取输入，%s用于读取字符串，这里身份证号后紧跟姓名，没有空格*/
    scanf("239999%4d%2d%2d%4d%s", &year, &month, &day, &code, name);

	/*使用？：检查日期范围和性别，并输出结果*/
    printf(((year == 2001 && month > 1 || (year == 2001 && month == 1 && day >= 24)) ||
           (year == 2002 && month < 2 || (year == 2002 && month == 2 && day <= 11))) &&
           (code % 100 / 10 % 2 == 1) ? "YES\n" : "NO\n");

    return 0;
}









