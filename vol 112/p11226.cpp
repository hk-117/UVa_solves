#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
bitset<10000010>bs;
vi Primes;
int dp[500005];
void sieve(ll upb){
  ll sieve_size=upb+1;
  bs.set();
  bs[0]=bs[1]=0;
  for(ll i=2;i<=sieve_size;i++){
    if(bs[i]){
      for(ll j=i*i;j<=sieve_size;j+=i) 
        bs[j]=0;
      Primes.push_back(i);
    }
  }
}
ll sumPF(ll N){
  if(dp[N]!= -1) return dp[N];
  ll Nn=N;
  ll PF_idx=0,PF=Primes[PF_idx],ans=0;
  while(PF*PF <= N){
    while(N%PF == 0){N/=PF;ans+=PF;}
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans+=N;
  dp[Nn]=ans;
  return ans;
}
int main(){
  int T,tc=0;
  sieve(1000);
  scanf("%d",&T);
  memset(dp,-1,sizeof dp);
  while(T--){
    int n,m,mx=INT_MIN;
    scanf("%d %d",&n,&m);
    if(n>m) swap(n,m);
    for(int i=n;i<=m;i++){
      int cnt=1,num=i;
      while(num != sumPF(num)){
        num=sumPF(num);
        cnt++;
      }
      mx=max(mx,cnt);
    }
    printf("Case #%d:\n%d\n",++tc,mx);
  }
}
