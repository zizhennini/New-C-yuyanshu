#include<stdio.h>
int main()
{
	int arr[10] = {[2]=2,[9]=11};				// 在C99标准中可以用指示器来对数组中指定位置进行赋值（即初始化）
	for (int i = 10-1; i >=0; i--)				// 指示器对对多维数组也有效（二维数组以上）
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

/*
还可以这样写

#include<stdio.h>
int main()
{
	int arr[10] = {[2]=2,3,5,[9]=11};
	for (int i = 10-1; i >=0; i--)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
*/