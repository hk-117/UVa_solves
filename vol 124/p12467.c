#include<stdio.h>
#include<string.h>
#define MAX 1000005
char P[MAX],T[MAX];
int b[MAX],m,res;
void kmpPreprocess(){
    int i=0,j=0;
    while(i<m){
        while(j>0 && T[i]!=P[j]){
            j=0;
        }
        if(T[i]==P[j])
            j++;
        b[i]=j;
        if(j>res)
            res=j;
        i++;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int i,j;
        scanf("%s",P);
        m=strlen(P);
        for(i=m-1,j=0;i>=0;i--){
            T[j++]=P[i];
        }
        T[m]='\0';
        res=-1;
        kmpPreprocess();
        for(i=res-1;i>=0;i--)
            printf("%c",P[i]);
        puts("");
    }
}
