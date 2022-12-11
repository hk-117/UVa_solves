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
vi PrimeFactors(ll N){
  ll PF_idx=0,PF=Primes[PF_idx];
  vi fact;
  while(PF*PF <= N){
    while(N%PF == 0){N/=PF;fact.push_back(PF);}
    PF=Primes[++PF_idx];
  }
  if(N!=1) {fact.push_back(N);}
  return fact;
}
ll digitSum(ll N){
  ll s=0;
  while(N){
    s+= N%10;
    N/=10;
  }
  return s;
}
bool isSmith(ll N){
  vi factors=PrimeFactors(N);
  if(factors.size()<2) return false;
  ll sm= digitSum(N),cm=0;
  for(int i=0;i<factors.size();i++){
    if(factors[i]<=9){
      cm+=factors[i];
    }
    else{
      cm+= digitSum(factors[i]);
    }
  }
  if(sm==cm) return true;
  return false;
}
int main(){
  ll N,T;
  sieve(100000);
  scanf("%lld",&T);
  while(T--){
    scanf("%lld",&N);
    bool found=false;
    N++;
    while(!found){
      if(isSmith(N)){
        printf("%lld\n",N);
        found=true;
      }
      else N++;
    }
  }
}
