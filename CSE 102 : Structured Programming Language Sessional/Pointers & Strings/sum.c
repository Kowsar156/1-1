#include<stdio.h>
int main()
{
    int i,n,sume=0,sumo=0;
    scanf("%d", &n);
    int *p = (int *)malloc(n*(sizeof(int)));
    for(i=0;i<n;i++){
        scanf("%d", (p+i));
        if(i%2==0){
            sume=sume+*(p+i);
        }
        else{
            sumo=sumo+*(p+i);
        }
    }
    if(sume>sumo)
        printf("Even index sum is greater");
    else if(sumo>sume)
        printf("Odd index sum is greater");
    else
        printf("Equal");
    free(p);
    return 0;
}
