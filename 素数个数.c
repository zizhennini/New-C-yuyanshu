#include<stdio.h>

int main() {
    int a, b, i, j, sum = 0;
    scanf("%d %d", &a, &b);

    for (i = a; i <= b; i++) {
        
        int temp = 1;
        for (j = 2; j * j <= i; j++) { 
            if (i % j == 0) {
                temp = 0;
                break;
            }
        }
        if (temp) {
            sum++;
        }
    }
    printf("%d\n", sum); 
    return 0;
}
