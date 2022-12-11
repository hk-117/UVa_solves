#include<bits/stdc++.h>
#define sieve_size 10010
using namespace std;
typedef long long ll;
bitset<sieve_size> bs;
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
}
int main(){
  int M;
  sieve();
  scanf("%d",&M);
  while(M--){
    int N,P;
    scanf("%d",&N);
    for(int i=N/2+1;i<=N;i++){
      if(bs[i]){
        P=i;
        break;
      }
    }
    printf("%d\n",P);
  }
}
