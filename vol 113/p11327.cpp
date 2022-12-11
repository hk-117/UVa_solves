#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
  return (b==0 ? a: gcd(b,a%b));
}
int main(){
  ll K;
  vector<ll> EulerPhi(200001);
  for(int i=1;i<=200000;i++) {
    EulerPhi[i]=i;
  }
  EulerPhi[1]++;
  for(int i=2;i<=200000;i++)
    if(EulerPhi[i]==i)
      for(int j=i;j<=200000;j+=i)
        EulerPhi[j]=(EulerPhi[j]/i)*(i-1);
  vector<ll> CSum=EulerPhi;
  for(int i=1;i<=200000;i++) CSum[i]=CSum[i-1]+CSum[i];
  ll D;
  while(scanf("%lld",&K)==1 && K){
    if(K==1){
      printf("0/1\n");
      continue;
    }
    if(K==2){
      printf("1/1\n");
      continue;
    }
    D= lower_bound(CSum.begin(),CSum.end(),K) - CSum.begin();
    if(CSum[D]==K){
      for(ll i=D-1;i>=1;i--){
        if(gcd(i,D)==1){
          printf("%lld/%lld\n",i,D);
          break;
        }
      }
    }
    if(CSum[D]>K){
      D;
      int req= K-CSum[D-1];
      for(ll i=1;i<D;i++){
        if(gcd(i,D)==1){
          req--;
        }
        if(req==0){
          printf("%lld/%lld\n",i,D);
          break;
        }
      }
    }
  }
}
