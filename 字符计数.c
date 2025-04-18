#include <stdio.h>
#include <string.h> 

int main()
{
    char ch[100];
    int sum = 0, sum1 = 0; 
    scanf("%s", ch);

    int len = strlen(ch); 
	int i=0;
    for ( i = 0; i < len; i++) { 
        if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') {
            sum++;
        } else {
            sum1++;
        }
    }
    printf("%d\n%d", sum, sum1);
    return 0;
}