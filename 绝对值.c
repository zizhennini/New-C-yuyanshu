#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	n > 0 ? printf("%d", n) : printf("%d", -n);
}