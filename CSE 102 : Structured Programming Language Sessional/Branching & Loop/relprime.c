#include<stdio.h>

int main()
{
    int n,gcd,i,j,check;
    scanf("%d", &n);
    gcd=j=0;
    i=n-1;
    check=0;
    for(i=n-1;i>0;i--){
        for(j=i;j>=1;j--){
            if(i%j==0&&n%j==0){
                gcd=j;
                break;
            }
        }
        if(gcd==1){
            check++;
        }
    }
    printf("%d", check);
    return 0;
}
