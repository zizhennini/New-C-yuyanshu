#include<stdio.h>

int main() {
    int n;
    
    

    while (1) {
    	
		scanf("%d", &n);
		if (n==0){
			break;
		}
        
		int g = n % 10;
        int s = (n / 10) % 10;
        int b = n / 100;

        if (g * g * g + s * s * s + b * b * b == n) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
        
    }


    return 0;
}