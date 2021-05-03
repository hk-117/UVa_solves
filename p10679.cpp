#include<bits/stdc++.h>
#define MAX_N 100005
#define MAX_Q 1005
using namespace std;
char T[MAX_N],P[MAX_Q];
int b[MAX_Q],n,m;

void kmpPreprocess(){
  int i=0,j=-1;
  b[0]=-1;
  while(i<m){
    while(j>=0 && P[i]!=P[j]) j=b[j];
    i++;j++;
    b[i]=j;
  }
}

bool kmpSearch(){
  int i=0,j=0;
  while(i<n){
    while(j>=0 && T[i]!=P[j]) j=b[j];
    i++;j++;
    if(j==m){
        return true;
    }
  }
  return false;
}

int main(){
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        int q;
        fgets(T,sizeof T,stdin);
        n=strcspn(T,"\n");
        T[n]='\0';
        scanf("%d",&q);
        getchar();
        while(q--){
            fgets(P,sizeof P,stdin);
            m=strcspn(P,"\n");
            P[m]='\0';
            kmpPreprocess();
            if(kmpSearch()){
                printf("y\n");
            }
            else{
                printf("n\n");
            }
        }
    }
}
