#include<stdio.h>
//#include<string.h>
int strl(char s[])
{
    int i;
    for(i=0;s[i]!='\0';i++){}
    return i;
}
int main()
{
    char s1[1000000],s2[1000000];
    char a;
    scanf("%[^\n]s", s1);
    scanf("%c", &a);
    scanf("%[^\n]s", s2);
    int i,j,count=0,c;
    for(i=0;i<strl(s1);i++){
        if(s1[i]==s2[0]){
            c=1;
            for(j=1;j<strl(s2);j++){
                if(s1[i+j]!=s2[j]){
                    break;
                }
                else{
                    c++;
                }
            }
            if(c==strl(s2)){
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}
