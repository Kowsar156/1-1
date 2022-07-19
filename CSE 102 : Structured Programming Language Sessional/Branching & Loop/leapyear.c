#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    ((n%4==0&&n%100!=0)||(n%400==0&&n%100==0))? printf("Leap Year"):printf("Not a leap year");
    return 0;
}
