#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);

    if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
        printf("'%c' is a Letter.\n", ch);
    } else {
        printf("'%c' is not a Letter.\n", ch);
    }
    return 0;
}