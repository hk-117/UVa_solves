#include<bits/stdc++.h>
#define sieve_size 32010
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
bool isValid(int fst,int lst,int diff){
  for(int d=1;d<diff;d++){
    if((bs[fst-d] && bs[fst-diff])||(bs[lst+d] && bs[lst+diff])){
      return true;
    }
  }
  if(bs[fst-diff] || bs[lst+diff]) 
    return false;
  return true;
}
int main(){
  int N,M;
  sieve();
  while(scanf("%d %d",&N,&M)==2 && (N||M)){
    vector<int> P,C;
    if(N>M) swap(N,M);
    for(int i=N;i<=M;i++){
      if(bs[i]){
        P.push_back(i);
      }
    }
    int cnt=0,diff;
    for(int i=1;i<P.size();i++){
      if(cnt==0){
        cnt+=2;
        diff= P[i]-P[i-1];
        C.push_back(P[i-1]);
        C.push_back(P[i]);
      }
      else{
        int dst=P[i]-P[i-1];
        if(dst==diff){
          C.push_back(P[i]);
          cnt++;
          if(i==P.size()-1 && cnt>=3){
            if(isValid(C[0],C[cnt-1],diff)){
              for(int i=0;i<cnt;i++){
                printf("%d",C[i]);
                if(i!=cnt-1)
                  printf(" ");
              }
              puts("");
            }
          }
        }
        else{
          if(cnt>=3){
            if(isValid(C[0],C[cnt-1],diff)){
              for(int i=0;i<cnt;i++){
                printf("%d",C[i]);
                if(i!=cnt-1)
                  printf(" ");
              }
              puts("");
            }
          }
          int tmp=C[cnt-1];
          C.clear();
          cnt=2;
          C.push_back(tmp);
          C.push_back(P[i]);
          diff=dst;
        }
      }
    }
  }
}
