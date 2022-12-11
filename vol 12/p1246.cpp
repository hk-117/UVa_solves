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
ll numDiv(ll N){
  if(N==1 || N==0) return N;
  ll PF_idx=0,PF=Primes[PF_idx],ans=1;
  while(PF*PF <= N){
    ll power=0;
    while(N%PF == 0) {N/=PF;power++;}
    ans*=(power+1);
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans*=2;
  return ans;
}
int main(){
  ll N,L,U;
  sieve(10050);
  cin>>N;
  while(N--){
    bool f=true;
    cin>>L>>U;
    for(ll i=L;i<=U;i++){
      ll tmp=numDiv(i);
      if(bs[tmp]){
        if(!f){
          cout<<" ";
        }
        if(f) f=false;
        cout<<i;
      }
    }
    if(f)
      cout<<-1<<endl;
    else
      cout<<endl;
  }
}
