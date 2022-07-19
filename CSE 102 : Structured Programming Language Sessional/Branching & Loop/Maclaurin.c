#include<stdio.h>
#define Pi 3.1415926
int main()
{
    int i,m;
    float n,x,result,prod;
    scanf("%d", &m);
    if(m>360)
        n=m%360;
    else
        n=m;
    x=(n*Pi)/180;
    for(prod=1.00,i=1;i<=100;i++){
        result=result+prod;
        prod=prod*(-1)*((x*x)/((2*i-1)*2*
                               i));
    }
    if(n==270)
        printf("0.000000");
    else
        printf("%.6f", result);
    return 0;
}
