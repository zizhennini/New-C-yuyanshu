/*
解题思路：用判别式temp = b*b - 4*a*c 看看有几个根或者没有根，然后可以算一下根（不管有没有根）的值,
		  最后根据判别式的结果判定一下根的情况，输出结果。
*/
#include<stdio.h>
#include<math.h>
int main(){

	double a,b,c,x1,x2,temp;
	
	scanf("%lf %lf %lf",&a,&b,&c);
	temp = b*b - 4*a*c;
	
	x1 = (-b + sqrt(b*b-4*a*c)) / (2*a);   /*换成这样x1 = (-b + sqrt(b*b-4*a*c)) / (2*a);x2 = (-b - sqrt(b*b-4*a*c)) / (2*a);差不多*/
	x2 = (-b - sqrt(b*b-4*a*c)) / (2*a);
	
	if (temp > 0){
		printf("%.6lf\n%.6lf",x1,x2);
	}else if (temp < 0){
		printf("This equation has no real root!");
	}else{
		printf("x1=x2=%.6lf",x1);
	}

	return 0; 
}
