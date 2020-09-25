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
ll numPF(ll N){
  if(N==1) return 0;
  ll PF_idx=0,PF=Primes[PF_idx],ans=0;
  while(PF*PF <= N){
    while(N%PF == 0){N/=PF;ans++;}
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans++;
  return ans;
}
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
  if(a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}
int main(){
  ll N,tc=0;
  sieve(1500);
  vector<pair<ll,ll>> T(2000001);
  T[0].first=0;
  T[0].second=0;
  for(ll i=1;i<=2000000;i++){
    T[i].first= i;
    T[i].second = numPF(i);
  }
  sort(T.begin(),T.end(),cmp);
  while(scanf("%lld",&N)==1 && N){
    printf("Case %lld: %lld\n", ++tc, T[N].first);
  }
}
