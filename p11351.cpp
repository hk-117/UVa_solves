#include<bits/stdc++.h>
using namespace std;
long long F(long long n,long long k){
    if(n==1)
        return 0;
    else
        return (F(n-1,k)+k)%n;
}
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        long long n,k;
        tc++;
        scanf("%lld %lld",&n,&k);
        printf("Case %d: %lld\n",tc,F(n,k)+1);
    }
}
