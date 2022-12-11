#include<bits/stdc++.h>
#define sieve_size 10000010
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
bitset<sieve_size> bs;
vi P;
void sieve(){
  bs.set();
  bs[0]=0;
  bs[1]=0;
  for(ll i=2;i*i<=(sieve_size);i++){
    if(bs[i]){
      for(ll j=i*i;j<=(sieve_size);j+=i){
        bs[j]=0;
      }
    }
  }
  for(ll i=0;i<=(sieve_size);i++){
    if(bs[i])
      P.push_back(i);
  }
}
bool isPrime(ll N){
  if(N<=sieve_size) return bs[N];
  ll sq = sqrt(N)+1;
  for(int i=0;i<(int) P.size() && P[i]<=sq;i++)
    if(N%P[i] == 0) return false;
  return true;
}
int main(){
  int N;
  sieve();
  while(scanf("%d",&N)==1){
    bool found=false;
    printf("%d is ",N);
    if(N%2){
      int p2=N-2;
      if(p2>2 && isPrime(p2)){
        printf("the sum of %d and %d.\n",2,p2);
      }
      else{
        puts("not the sum of two primes!");
      }
      found=true;
    }
    else{
      for(int i=N/2+1;i<N;i++){
        if(isPrime(i) && isPrime(N-i) && (N-i)%2){
          found=true;
          printf("the sum of %d and %d.\n",N-i,i);
          break;
        }
      }
    }
    if(!found){
      puts("not the sum of two primes!");
    }
  }
}
