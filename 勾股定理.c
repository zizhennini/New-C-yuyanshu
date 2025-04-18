#include<stdio.h>
int main(){
    int n,a,b,c;

    scanf("%d",&n);

    a=2*n+1;

    b=2*n*(n+1);

    c=b+1;

    printf("(%d,%d,%d)",a,b,c);

    return 0;
}
