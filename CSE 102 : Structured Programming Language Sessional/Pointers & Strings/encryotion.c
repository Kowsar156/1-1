#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d", &n);
    char *p = (char *)malloc(n*sizeof(char));
    int *q = (int *)malloc(n*sizeof(int));
    long long int *d = (long long int *)malloc((n/3)*sizeof(long long int));
    scanf("%[^\n]s", p);

    *d = (long long int *)p;
    for(i=0;i<(n/3);i++){
        printf("%lld ", *(d+i));
    }
    free(p);
    free(q);
    free(d);
    return 0;

}
