#include<stdio.h>

int main()
{
    int n,remain,max,num;
    float m;
    scanf("%d", &n);
    max=0;
    while(n!=0){
        remain=n%10;
        if(max<remain){
            max=remain;
            num=0;
        }
        if(remain==max){
            num++;
        }
        m=n/10;
        n=(int)m;
    }
    printf("%d", num);
    return 0;
}
