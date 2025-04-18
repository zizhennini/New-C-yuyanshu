#include<stdio.h>
int main() {

	int sum = 0;
	char ch;

	while ((ch = getchar()) != '#') {

		if ('0' <= ch && ch <= '9') {
			sum += ch - '0';
		}
	}
	printf("%d\n", sum);
	return 0;
}
