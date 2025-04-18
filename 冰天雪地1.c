/*
解题思路：先判断是否免费，再判断是否优惠，最后输出门票费用，注意年龄范围的判断。各年龄的判断条件如下： 
70岁以上的老人不论男女都是免费的只判断年龄不用判断是哪个类别，65岁以上的女性要判断一下年龄和性别就行了，
11岁以下的儿童也是判断一下年龄，残疾人士、现役军人和消防救援人员只用判断类别就可以了，如果符合这些条件，
就输出0元，不用判断其他条件了。
18周岁以下12周岁以上的青少年只判断年龄、60-69岁的男性判断年龄和性别，55-64岁的女性判断年龄和性别，如果
符合这些条件，就输出120，不用判断其他条件了。
其他的正常票价是180元，
*/
#include <stdio.h>

int main() {
    int age;
    char sex, category;

    scanf("%d %c %c", &age, &sex, &category); 

    
    if ((age >= 70 || (age >= 65 && sex == 'F') || (age <= 11)) || category == 'C' || category == 'X') {
        printf("0");
    } else if ((age >= 12 && age <= 18) || (age >= 60 && age <= 69 && category == 'P') || (age >= 55 && age <= 64 && category == 'P')) {
        printf("120");
    } else {
        printf("180");
    }

    return 0;
}