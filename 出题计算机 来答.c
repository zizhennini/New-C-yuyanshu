#include<stdio.h>

int main() {

	int m, n;
	char ch;

	scanf("%d%c%d", &m,&ch,&n);
	if (ch == '+') {
		printf("%d+%d=%d", m, n, m + n);
	}else if (ch == '-'){
		printf("%d-%d=%d", m, n, m - n);
	}else if (ch == '*'){
		printf("%d*%d=%d", m, n, m * n);
	}else if (ch == '/') {
		if (n ==0){
		printf("IIIegal operation");
		}else{
		printf("%d+%d=%d", m, n, m + n);
		}
	}

	return 0;
}