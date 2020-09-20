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
void primeFactors(ll N,map<ll,ll> &factors){
  ll PF_idx=0,PF=Primes[PF_idx];
  while(PF*PF <= N){
    while(N%PF == 0) {N/=PF;factors[PF]++;}
    PF=Primes[++PF_idx];
  }
  if(N!=1) {factors[N]++;}
}
ll getPow(ll n,ll p){
  int pw=0;
  n/=p;
  do{
    pw+= n;
    n/=p;
  }while(n>0);
  return pw;
}
int main(){
  ll n,m;
  sieve(50000);
  while(cin>>n>>m){
    map<ll,ll> MF;
    bool divides=true;;
    if(n==0 && m!=1) divides= false;
    else if(n==0&&m==1) divides= true;
    else if(m==0) divides= false;
    else if(m==n||m==1) divides= true;
    else if (n >= m) divides= true;
    else{
      primeFactors(m,MF);
      ll PF,N;
      for(auto it=MF.begin();it!=MF.end();it++){
        if(it->second > getPow(n,it->first)){
          divides=false;
          break;
        }
      }
    }
    if(divides){
      printf("%lld divides %lld!\n",m,n);
    }
    else{
      printf("%lld does not divide %lld!\n",m,n);
    }
  }
}
