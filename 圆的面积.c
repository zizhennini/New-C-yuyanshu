#include<stdio.h>
#define PI 3.14159265		
int main(){
	double r,area;
	scanf("%lf",&r);
	area = PI * r * r;
	printf("%.4lf",area);
	return 0;
}
