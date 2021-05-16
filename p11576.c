#include<stdio.h>
#include<string.h>
#define MAX 105

char T[MAX],P[MAX];
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
    int n,w;
    scanf("%d",&n);
    while(n--){
        int i,total=0;
        scanf("%d %d %s",&m,&w,T);
        for(i=1;i<w;i++){
            scanf("%s",P);
            kmpPreprocess();
            total+= (m-kmpSearch());
            strcpy(T,P);
        }
        printf("%d\n",total+m);
    }
}
