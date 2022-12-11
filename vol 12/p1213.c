#include<stdio.h>
#include<string.h>
#define MAX 1120
int P[187],bs[MAX],N,K;
long long dp[187][MAX+1][15];
void sieve(){
    int ssize=1120,i,j,ps=0;
    bs[0]=bs[1]=1;
    for(i=2;i<ssize;i++){
        if(!bs[i]){
            for(j=i*i;j<ssize;j+=i){
                bs[j]=1;
            }
            P[ps++]=i;
        }
    }
}
long long findMax(int idx,int remN,int remK){
    if(remK==0 && remN==0) return 1;
    if(remN<0 || remK==0 || idx>=187) return 0;
    if(dp[idx][remN][remK]!=-1) return dp[idx][remN][remK];
    dp[idx][remN][remK]=findMax(idx+1,remN-P[idx],remK-1)+findMax(idx+1,remN,remK);
    return dp[idx][remN][remK];
}
int main(){
    sieve();
    memset(dp,-1,sizeof dp);
    while(scanf("%d %d",&N,&K)==2 && (N||K)){
        printf("%lld\n",findMax(0,N,K));
    }
}
