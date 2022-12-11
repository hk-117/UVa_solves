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
  ll g;
  vi F;
  string line;
  sieve(250);
  while(getline(cin,line),line!="0"){
    g=1;
    stringstream ss(line);
    ll a,b;
    while(ss>>a>>b){
      g*=pow(a,b);
    }
    F= primeFactors(g-1);
    map<ll,ll,greater<ll>> frqs;
    for(auto it=F.begin();it!=F.end();it++){
      frqs[*it]++;
    }
    for(auto it=frqs.begin();it!=frqs.end();it++){
      if(it!=frqs.begin())
        printf(" %lld %lld",it->first,it->second);
      else{
        printf("%lld %lld",it->first,it->second);
      }
    }
    printf("\n");
  }
}
