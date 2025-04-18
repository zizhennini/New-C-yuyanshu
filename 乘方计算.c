#include<stdio.h>
#include<math.h>

//法一：
int main(){
	
	int a,n,i,sum=1;
	
	scanf("%d %d",&a,&n);
	
	for (int i=1;i<=n;i++){
		sum *=a;
	}
	printf("%d",sum);
	
	return 0;
}


//法二：
//int main(){
//
//	int a,n,sum=1;
//	scanf("%d %d",&a,&n);
//	
//	sum=pow(a,n);
//	
//	printf("%d",sum);
//	return 0;
//}
