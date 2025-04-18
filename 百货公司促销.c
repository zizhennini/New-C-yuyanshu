#include<stdio.h>
int main() {

	double sum, sum2, temp;

	scanf_s("%lf %lf", &sum, &sum2);
	if (sum < 500) {
		temp = sum; 
		printf("0%%\n%.2lf\n%.2lf", temp, sum2 - temp);
	}
	else if (sum < 1000) {
		temp = sum * 0.95;
		printf("95%%\n%.2lf\n%.2lf", temp, sum2 - temp);
	}
	else if (sum < 2000) {
		temp = sum * 0.90;
		printf("90%%\n%.2lf\n%.2lf", temp, sum2 - temp);
	}
	else if (sum < 3000) {
		temp = sum * 0.85;
		printf("85%%\n%.2lf\n%.2lf", temp, sum2 - temp);
	}
	else {
		temp = sum * 0.80;
		printf("80%%\n%.2lf\n%.2lf", temp, sum2 - temp);
	}

	return 0;
}