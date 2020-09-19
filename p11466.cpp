#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
bitset<10000010>bs;
vi Primes;
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
vi primeFactors(ll N){
  vi factors;
  ll PF_idx=0,PF=Primes[PF_idx];
  while(PF*PF <= N){
    while(N%PF == 0) {N/=PF;factors.push_back(PF);}
    PF=Primes[++PF_idx];
  }
  if(N!=1) factors.push_back(N);
  return factors;
}
int main(){
  ll g,N;
  vi F;
  sieve(10000000);
  while(scanf("%lld",&N)==1 && N!=0){
    F= primeFactors(abs(N));
    set<ll,greater<ll>> A(F.begin(),F.end());
    if(!(A.size()>1)){
      printf("-1\n");
    }
    else{
      printf("%lld\n",*A.begin());
    }
  }
}
