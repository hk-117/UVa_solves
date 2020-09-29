#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
typedef long long ll;
int main(){
  ll G,L;
  while(scanf("%lld %lld",&L,&G)==2 && (L||G)){
    vector<pair<ll,ll>> interval;
    ll x,r;
    R(i,0,G,1){
      scanf("%lld %lld",&x,&r);
      interval.push_back(make_pair(x-r,x+r));
    }
    sort(interval.begin(),interval.end());
    bool possible=false;
    ll ch,i,j;
    ll Right=0;
    for(i=0,j=0;i<interval.size();i++){
      ll tmp=Right;
      ch=-1;
      while(j<interval.size() && interval[j].first<=Right){
        if(interval[j].second>tmp){
          tmp=interval[j].second;
          ch=j;
        }
        j++;
      }
      if(tmp>=L){
        printf("%lld\n",G-(i+1));
        possible=true;
        break;
      }
      if(ch==-1)
        break;
      Right=tmp;
    }
    if(!possible)
      puts("-1");
  }
}
