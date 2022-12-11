#include<cstdio>
#include<cstring>
using namespace std;
long long D,N,M,Q,Val[205],ans,dp[201][11][21];
long long Mod(long long S){
    if(S>=0) return S%D;
    return (D+(S%D))%D;
}
long long findWay(int i,int rM,long long S){
    if(S==0 && rM==0) return 1;
    if(i==N || rM==0) return 0;
    if(dp[i][rM][S]!=-1) return dp[i][rM][S];
    return dp[i][rM][S]=findWay(i+1,rM-1,Mod(S+Val[i]))+findWay(i+1,rM,S);
}
int main(){
    int tc=0,i;
    while(scanf("%lld %lld",&N,&Q)==2 && (N||Q)){
        tc++;
        for(i=0;i<N;i++){
            scanf("%lld",&Val[i]);
        }
        printf("SET %d:\n",tc);
        for(i=1;i<=Q;i++){
            scanf("%lld %lld",&D,&M);
            memset(dp,-1,sizeof dp);
            ans=findWay(0,M,0);
            printf("QUERY %d: %lld\n",i,ans);
        }
    }
}
