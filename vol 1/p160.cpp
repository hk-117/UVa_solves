#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
bitset<110>bs;
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
  ll n;
  sieve(100);
  while(cin>>n,n){
    map<ll,ll> Cnt;
    for(int i=0;i<Primes.size() && Primes[i]<=n;i++){
      Cnt[Primes[i]]+= getPow(n,Primes[i]);
    }
    printf("%3lld! =",n);
    int c=0;
    for(auto it=Cnt.begin();it!=Cnt.end();it++){
      c++;
      if(c==16) printf("\n      ");
      printf("%3lld",it->second);
    }
    puts("");
  }
}
