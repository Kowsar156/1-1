#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,n;
    scanf("%d", &n);
    int *p = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", (p+i));
    }

    int *m = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        *(m+i)=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(*(p+i)==*(p+j)){
                *(m+i)=*(m+i)+1;
            }
        }
    }
    int max=0;
    for(i=0;i<n;i++){
        if(*(m+i)>max){
            max=*(m+i);
        }
    }
    for(i=0;i<n;i++){
        if(*(m+i)==max){
            printf("%d ", *(p+i));
        }
    }
    return 0;
}
