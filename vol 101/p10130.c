#include<stdio.h>
#include<string.h>
#define MAX_N 1010
#define MAX_W 40
#define max(a,b) (a)>(b)?(a):(b)
int V[MAX_N],W[MAX_N],N,MW,dp[MAX_N][MAX_W];
int findMax(int object,int weight){
    if(object==N || weight==0) return 0;
    if(dp[object][weight] != -1) return dp[object][weight];
    if(W[object]>weight){
        dp[object][weight]=findMax(object+1,weight);
        return dp[object][weight];
    }
    dp[object][weight]=max(findMax(object+1,weight),V[object]+findMax(object+1,weight-W[object]));
    return dp[object][weight];
}
int main(){
    int i,T,G,tot=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%d %d",&V[i],&W[i]);
        }
        memset(dp,-1,sizeof dp);
        tot=0;
        scanf("%d",&G);
        while(G--){
            scanf("%d",&MW);
            tot += findMax(0,MW);
        }
        printf("%d\n",tot);
    }
}
