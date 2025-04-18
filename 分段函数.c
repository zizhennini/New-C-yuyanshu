#include<stdio.h>
#include<math.h>
int main(){

	double x,y;
	
	scanf("%lf",&x);
	if (1 <= x && x < 2){
		printf("%.6lf",3*x+5);
	}else if (2<=x && x<3){
		printf("%.6lf",2*sin(x)-1);
	}else if (3<=x && x<4){
		printf("%.6lf",sqrt(1+x*x));
	}else if (4<=x && x<5){
		printf("%.6lf",x*x-2*x+5);
	}else{
		printf("No define");
	}

	return 0;
}
