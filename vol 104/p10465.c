#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?(a):(b)
int m,n,t,dp[10005];
int main(){
    int i;
    while(scanf("%d %d %d",&m,&n,&t)==3){
        memset(dp,0,(t+1)* sizeof dp[0]);
        dp[m]=1;
        dp[n]=1;
        for(i=1;i<=t;i++){
            if(dp[i]>0){
                if(i+m <= t)
                    dp[i+m]=max(dp[i+m],dp[i]+1);
                if(i+n <= t)
                    dp[i+n]=max(dp[i+n],dp[i]+1);
            }
        }
        i=t;
        while(dp[i]==0 && i>0) i--;
        printf("%d",dp[i]);
        if(i!=t){
            printf(" %d",t-i);
        }
        puts("");
    }
}
