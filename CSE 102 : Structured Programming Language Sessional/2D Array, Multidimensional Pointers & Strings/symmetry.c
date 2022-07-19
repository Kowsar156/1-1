#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j,count=1;
    scanf("%d", &n);
    //int *x = (int *)malloc(n*sizeof(int));
    //int *y = (int *)malloc(n*sizeof(int));
    int **p = NULL;
    int **q = NULL;
    p = (int **)malloc(n*sizeof(int));
    q = (int **)malloc(n*sizeof(int));
    for(j=0;j<n;j++){
        q[j] =  (int *)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        p[i] = (int *)malloc(n*sizeof(int));

        for(j=0;j<n;j++){
            scanf("%d", (*(p+i)+j));
            *(*(q+j)+i)=*(*(p+i)+j);
        }
    }
    for(i=0;i<n;i++){

        for(j=0;j<n;j++){
            if(*(*(q+i)+j)!=*(*(p+i)+j)){
                count=0;
                break;
            }
        }
        if(count==0){
            break;
        }
    }
    if(count==0){
            printf("NO");
    }
    else
        printf("YES");
        free(p);
        free(q);

    return 0;


}
