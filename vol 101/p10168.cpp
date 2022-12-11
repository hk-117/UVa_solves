#include<bits/stdc++.h>
#define sieve_size 10000010
using namespace std;
typedef long long ll;
vector<int> P;
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
  for(int i=2;i<=sieve_size-1;i++){
    if(bs[i])
      P.push_back((int)i);
  }
}
int main(){
  int N;
  sieve();
  while(scanf("%d",&N)==1){
    bool possible=false;
    for(int i=0;i<P.size() && (!possible) && P[i]<N;i++){
      for(int j=0;j<P.size() && (!possible) && P[i]+P[j]<N;j++){
        for(int k=0;k<P.size() && (!possible) && P[i]+P[j]+P[k]<N;k++){
          if(bs[N-(P[i]+P[j]+P[k])]){
            possible=true;
            printf("%d %d %d %d\n",P[i],P[j],P[k],(N-(P[i]+P[j]+P[k])));
          }
        }
      }
    }
    if(!possible){
      puts("Impossible.");
    }
  }
}
