#include<stdio.h>

#include<stdlib.h>
#include<math.h>

//int *p = (int *)malloc(2*sizeof(int));
int triangle(float a,float b,float c, int *p)
{
    if((a+b)>c&&(b+c)>a&&(c+a)>b){
        *p=1;
    }
    else{
        *p=0;
    }

    if((pow(a,2)+pow(b,2)==pow(c,2))||(pow(b,2)+pow(c,2)==pow(a,2))||(pow(a,2)+pow(c,2)==pow(b,2))){
        *(p+1)=1;
    }
    else{
        *(p+1)=0;
    }
}

int main()
{
    float x,y,z;
    int *p = (int *)malloc(2*sizeof(int));
    scanf("%f %f %f", &x, &y, &z);
    triangle(x,y,z,p);
    if(*p==1){
        printf("Triangle is possible\n");
    }
    else{
        printf("Triangle is not possible\n");
    }
    if(*(p+1)==1&&*p==1){
        printf("The traingle is right angled\n");
    }
    else{
        printf("The triangle is not right angled\n");
    }
    free(p);
    return 0;
}
