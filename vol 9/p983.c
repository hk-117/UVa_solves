#include<stdio.h>
#define MAX 1005
int N,M;
long long Mat[MAX][MAX];
int main(){
    int i,j,k,l,tc=0;
    long long cur,ans;
    while(scanf("%d %d",&N,&M)==2){
        if(tc++)
            putchar('\n');
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                scanf("%lld",&Mat[i][j]);
                if(j>0) Mat[i][j]+=Mat[i][j-1];
                if(i>0) Mat[i][j]+=Mat[i-1][j];
                if(i>0 && j>0) Mat[i][j]-=Mat[i-1][j-1];
            }
        }
        ans=0;
        for(i=0;i<N-M+1;i++){
            for(j=0;j<N-M+1;j++){
                cur= Mat[i+M-1][j+M-1];
                if(i>0) cur-=Mat[i-1][j+M-1];
                if(j>0) cur-=Mat[i+M-1][j-1];
                if(i>0 && j>0) cur+=Mat[i-1][j-1];
                printf("%lld\n",cur);
                ans+=cur;
            }
        }
        printf("%lld\n",ans);
    }
}
