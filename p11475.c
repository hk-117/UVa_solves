#include<stdio.h>
#include<string.h>
#define MAX 100010

char P[MAX],T[MAX];
int b[MAX],m;

void kmpPreprocess(){
    int i=1,j=0;
    while(i<m){
        while(j>0 && P[i]!=P[j]){
            j=b[j-1];
        }
        if(P[i]==P[j])
            j++;
        b[i]=j;
        i++;
    }
}

int kmpSearch(){
    int i=0,j=0;
    while(i<m){
        if(T[i]==P[j]){
            i++;
            j++;
        }
        else if(j>0){
            j=b[j-1];
        }
        else
            i++;
    }
    return j;
}

int main(){
    int i,pos;
    while(fgets(T,sizeof T,stdin)){
        m=strcspn(T,"\n");
        T[m]='\0';
        for(i=0;i<m;i++)
            P[i]=T[m-i-1];
        P[m]='\0';
        kmpPreprocess();
        pos=kmpSearch();
        printf("%s",T);
        for(i=pos;i<m;i++){
            printf("%c",P[i]);
        }
        printf("\n");
    }
}

