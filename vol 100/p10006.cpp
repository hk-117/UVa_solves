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
vi PrimeFactors(ll N,int &pf,int &diffpf){
  ll PF_idx=0,PF=Primes[PF_idx];
  vi fact;
  pf=0;
  diffpf=0;
  while(PF*PF <= N){
    if(N%PF==0) diffpf++;
    while(N%PF == 0){N/=PF;fact.push_back(PF);pf++;}
    PF=Primes[++PF_idx];
  }
  if(N!=1) {fact.push_back(N);diffpf++;pf++;}
  return fact;
}
bool carmiChael(ll N){
  if(N%2==0 || bs[N]) return false;
  int pf,diffpf;
  vi factors= PrimeFactors(N,pf,diffpf);
  if(pf!=diffpf) return false;
  for(int i=0;i<factors.size();i++){
    if((N-1) % (factors[i]-1) != 0)
      return false;
  }
  return true;
}
int main(){
  ll N;
  sieve(65000);
  while(scanf("%lld",&N)==1 && N){
    if(carmiChael(N)){
      printf("The number %lld is a Carmichael number.\n",N);
    }
    else{
      printf("%lld is normal.\n",N);
    }
  }
}
