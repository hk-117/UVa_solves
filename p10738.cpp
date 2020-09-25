#include<bits/stdc++.h>
#define inf 999999999
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int numDiffPF[1000005],numpF[1000005],MU[1000005];
vi Primes;
void mod_sieve(ll upb){
  ll sieve_size=upb+1;
  numDiffPF[0]=numDiffPF[1]=1;
  for(ll i=2;i<=sieve_size;i++){
    if(numDiffPF[i]==0){
      for(ll j=i;j<=sieve_size;j+=i) 
        numDiffPF[j]++;
      Primes.push_back(i);
    }
  }
}
ll numPF(ll N){
  ll PF_idx=0,PF=Primes[PF_idx],ans=0;
  while(PF*PF <= N){
    while(N%PF==0) {N/=PF;ans++;}
    PF= Primes[++PF_idx];
  }
  if(N!=1) ans++;
  return ans;
}
ll getMuValue(ll N){
  if(MU[N] != -inf) return MU[N];
  if(N==1) return MU[N]=1;
  if(numpF[N]!=numDiffPF[N]){
    return MU[N]=0;
  }
  else{
    if(numpF[N]%2) return MU[N]=-1;
    else return MU[N]=1;
  }
}
int main(){
  ll N;
  mod_sieve(1000000);
  for(int i=2;i<=1000000;i++){
    numpF[i]=numPF(i);
    MU[i]= -inf;
  }
  MU[0]=MU[1]=-inf;
  while(scanf("%lld",&N)==1 && N){
    int mu=0,muN;
    for(ll i=1;i<=N;i++){
      muN=getMuValue(i);
      mu+= muN;
    }
    printf("%8lld%8d%8d\n",N,muN,mu);
  }
}
