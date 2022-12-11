#include<bits/stdc++.h>
#define MX 1000100001
using namespace std;
typedef long long ll;
int main(){
  ll N,RNG;
  map<int,int> cnt;
  vector<int> Cab;
  for(int i=1;i<=1001;i++){
    for(int j=1;j<=1001;j++){
      if(i!=j){
        ll tmp= pow(i,3)+pow(j,3);
        if(tmp>MX-1) break;
        cnt[tmp]++;
      }
    }
  }
  for(auto it=cnt.begin();it!=cnt.end();it++){
    if(it->second >=4)
      Cab.push_back(it->first);
  }
  while(scanf("%lld %lld",&N,&RNG)==2){
    bool found=false;
    auto it= lower_bound(Cab.begin(),Cab.end(),N);
    if(it!= Cab.end()){
      while(*it >= N && *it <= N+RNG){
        printf("%d\n",*it);
        it++;
        found=true;
      }
    }
    if(!found)
      puts("None");
  }
}
