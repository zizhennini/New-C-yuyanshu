/*
很多网友在晒男朋友给买十根烤肠的视频，如果你还没有收到也不要难过，因为你那么可爱，早晚会遇到给你买十根烤肠的人！
每一根烤肠都代表一份爱心，已知第一根烤肠的爱心价值为a1，第二根烤肠的爱心价值为a2,以后每根烤肠的爱心价值都比前一根多(a2-a1)。
假设你收到n根烤肠，那么总的爱心价值多少呢？
输入格式:
三个正整数，a1、a2和N。其中a2>a1>0，n>2.
*/

#include <stdio.h>

int main() {
    int a1, a2,N,d,an,Sum;
    scanf("%d %d %d", &a1, &a2, &N);
    d = a2 - a1;
    an = a1 + (N -1) * d;
	Sum = (N * (a1+an)) / 2;
    printf("%d",Sum);
    return 0;
}


