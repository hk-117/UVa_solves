#include<bits/stdc++.h>
#define SD 1
#define ND 0
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
bitset<10000010>bs;
vi Primes;
int dp[2][100005];
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
ll sumDiv(ll N){
  if(dp[SD][N]!=-1) return dp[SD][N];
  ll PF_idx=0,PF=Primes[PF_idx],ans=1,nm=N;
  while(PF*PF <= N){
    ll power=0;
    while(N%PF == 0) {N/=PF;power++;}
    ans *= ((ll)pow((double)PF,power+1.0)-1)/(PF-1);
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans *= ((ll)pow((double)N,2.0)-1)/(N-1);
  return dp[SD][nm]=ans;
}
ll numDiv(ll N){
  if(dp[ND][N]!=-1) return dp[ND][N];
  ll PF_idx=0,PF=Primes[PF_idx],ans=1,nm=N;
  while(PF*PF <= N){
    ll power=0;
    while(N%PF == 0) {N/=PF;power++;}
    ans *= (power+1);
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans *= 2;
  return dp[ND][nm]=ans;
}
int main(){
  int T;
  ll A,B,K,Sigma,Digma;
  scanf("%d",&T);
  memset(dp,-1,sizeof dp);
  dp[0][1]=1;
  dp[1][1]=1;
  sieve(400);
  while(T--){
    Sigma=0;
    Digma=0;
    scanf("%lld %lld %lld",&A,&B,&K);
    for(ll i=A;i<=B;i++){
      if(i%K==0){
        Digma+= numDiv(i);
        Sigma+= sumDiv(i);
      }
    }
    printf("%lld %lld\n",Digma,Sigma);
  }
}
