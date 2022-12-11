#include<cstdio>
#include<cstring>
#define max(a,b) (a)>(b)?(a):(b)
#define R(i,a,b,c) for(i=a;i<b;i+=c)
using namespace std;
int T,W,N,D[35],Q[35],dp[35][1005],solu[35];
int findMax(int idx,int tm){
    if(idx==N || tm==0) return 0;
    if(dp[idx][tm]!=-1) return dp[idx][tm];
    if(W*D[idx]+2*W*D[idx] > tm){
        return dp[idx][tm]=findMax(idx+1,tm);
    }
    return dp[idx][tm]=max(findMax(idx+1,tm),Q[idx]+findMax(idx+1,tm-2*D[idx]*W-D[idx]*W));
}
void printSol(int idx,int tm,int mx){
    int i,a;
    if(tm<0 || idx==N) return;
    for(i=idx;i<N;i++){
        a= tm-2*D[i]*W-D[i]*W;
        if(mx==findMax(i,tm) && Q[i]==mx-findMax(i+1,a)){
             solu[0]++;
             solu[solu[0]]=i;
             printSol(i+1,a,mx-Q[i]);
             break;
        }
    }
}
int main(){
    int i,dtset=0,ans;
    while(scanf("%d %d",&T,&W)==2){
        if(dtset++)
            putchar('\n');
        scanf("%d",&N);
        R(i,0,N,1){
            scanf("%d %d",&D[i],&Q[i]);
        }
        memset(dp,-1,sizeof dp);
        ans= findMax(0,T);
        printf("%d\n",ans);
        solu[0]=0;
        printSol(0,T,ans);
        printf("%d\n",solu[0]);
        R(i,1,solu[0]+1,1){
            printf("%d %d\n",D[solu[i]],Q[solu[i]]);
        }
    }
}
