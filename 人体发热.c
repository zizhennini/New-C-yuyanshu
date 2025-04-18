#include<stdio.h>


int main(){

    double t;         

    scanf("%lf",&t);  

    t > 37.0 ?  printf("have a fever") : printf("no") ; //用三目运算符简化代码，输出结果

    return 0;

}

//int main(){
//	
//	double t;
//	scanf("%lf",&t);
//	if (t>37.0){
//		printf("have a fever");
//	}else{
//		printf("no");
//	}
//	return 0;
//}