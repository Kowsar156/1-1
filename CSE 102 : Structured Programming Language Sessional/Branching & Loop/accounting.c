#include<stdio.h>

int main()
{
    int n;
    float price;
    scanf("%d", &n);
    if(n>200)
        price=50+80+((n-200)*1.2);
    else if(n>100&&n<=200)
        price=50+((n-100)*0.8);
    else
        price=n*0.5;
    printf("%.2f", price);
    return 0;
}
