#include<stdio.h>
#include<math.h>
int main(){
    int t=0,tc;
    scanf("%d",&tc);
    while(tc--){
        long long int N,pw;
        int ans;
        scanf("%lld",&N);
        N++;
        ans=log(N)/log(2);
        pw=pow(2,ans);
        if(pw<N)
            ans++;
        printf("Case %d: %d\n",++t,ans);
    }
}
