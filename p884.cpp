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
  ll PF_idx=0,PF=Primes[PF_idx],ans=0;
  while(PF*PF <= N){
    while(N%PF == 0) {N/=PF;ans++;}
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans++;
  return ans;
}
int main(){
  ll N;
  sieve(1050);
  vi NMPF(1000001,0);
  for(ll i=2;i<1000001;i++){
    NMPF[i]=NMPF[i-1]+numPF(i);
  }
  while(cin>>N){
    cout<<NMPF[N]<<endl;
  }
}
