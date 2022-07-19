#include<stdio.h>

int big(int a)
{
    int b,max;
    max=a%10;
    while(a/10!=0){
        b=a%10;
        a=a/10;
        if(b>max){
            max=b;
        }
    }
    return max;
}

int main()
{
    int n,result;
    scanf("%d", &n);
    result=big(n);
    printf("%d", result);
    return 0;
}
