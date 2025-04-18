
// 为了跟样例输出一致，只能写复杂一点

#include<stdio.h>
int main(){

	int n;
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		if (i==1){
			printf("%d",i);
		}
		if (i>=2 && i % 2==1){
			printf(",%d",i);
		}
	}

	return 0;
}
