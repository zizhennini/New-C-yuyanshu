#include<stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

	int m=1;
    for (int i = a; i <= b; i++) {
        
        int temp = 1;
        for (int j = 2; j * j <= i; j++) {   // 通过j * j <= i（即相当于sqrt（））减少时间
            if (i % j == 0) {
                temp = 0;
                break;
            }
        }
        if (temp) {					// 为了跟样例输出一致，只能写复杂一点
            if (m){
				printf("%d", i); 
				m=0; 
				}else{
					printf(",%d", i);
					}
            
        }
    }
   
    return 0;
}
