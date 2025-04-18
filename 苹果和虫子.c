#include<stdio.h>
int main() {

	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);

	y % x ? printf("%d", n - (y / x + 1)) : printf("%d", n - y / x);
	return 0;
}
