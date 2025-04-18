#include<stdio.h>
#define PI 3.14159265

int main(){
	
	double r,S,V;
	scanf("%lf",&r);
	S = 4 * PI * r * r;
	V = 4.0 / 3.0 * PI * r * r * r;
	printf("%.2lf %.2lf",S,V);
		
	return 0;
}
