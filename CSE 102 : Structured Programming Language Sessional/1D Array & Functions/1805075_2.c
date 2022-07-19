#include<stdio.h>

int main()
{
    int num[105],place[105];
    int i,j,max,x;
    scanf("%d", &x);
    for(i=0;i<x;i++){
        scanf("%d", &num[i]);
        place[i]=0;
    }
    for(i=0;i<x;i++){
        for(j=0;j<i;j++){
            if(num[j]==num[i]){
                place[i]++;
            }
        }
    }
    max=place[0];
    for(i=1;i<x;i++){
        if(place[i]>max){
            max=num[i];
        }
    }
    printf("%d", max);
    return 0;
}
