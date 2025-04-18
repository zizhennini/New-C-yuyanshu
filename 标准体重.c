#include<stdio.h>
int main(){
	float h;
	scanf("%f",&h);
	printf("%.2fKG",(h * 100 - 80) * 0.7);
	return 0;
}
