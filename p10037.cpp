#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,tmp;
    cin>>n;
    multiset<int> People;
    for(int i=1;i<=n;i++){
      cin>>tmp;
      People.insert(tmp);
    }
    if(n<=1){
      cout<< *People.begin()<<endl;
      cout<< *People.begin()<<endl;
      if(t)
        cout<<endl;
      continue;
    }
    multiset<int> Reached;
    vector<pair<int,int>> Res;
    int tim=0;
    bool Forward=true;
    while(People.size()){
      if(People.size()==2){
        auto it=People.begin();
        int a=*it;
        it++;
        int b=*it;
        Res.push_back(make_pair(a,b));
        tim+=b;
        People.clear();
        continue;
      }
      if(People.size()==3){
        auto it=People.begin();
        int a=*it;
        it++;
        int b=*it;
        it++;
        int c=*it;
        Res.push_back(make_pair(a,b));
        tim+=b;
        Res.push_back(make_pair(a,-1));
        tim+=a;
        Res.push_back(make_pair(a,c));
        tim+=c;
        People.clear();
        continue;
      }
      int a,b,A,B;
      auto it=People.begin();
      A=*it;
      it++;
      B=*it;
      it--;
      auto bt= People.end();
      bt--;
      a= *bt;
      bt--;
      b= *bt;
      if(b+A < 2*B){
        Res.push_back(make_pair(A,a));
        tim+=a;
        People.erase(prev(People.end()));
        Res.push_back(make_pair(A,-1));
        tim+=A;
        Res.push_back(make_pair(A,b));
        tim+=b;
        People.erase(prev(People.end()));
        Res.push_back(make_pair(A,-1));
        tim+=A;
      }
      else{
        Res.push_back(make_pair(A,B));
        tim+=B;
        Res.push_back(make_pair(A,-1));
        tim+=A;
        Res.push_back(make_pair(b,a));
        tim+=a;
        People.erase(prev(People.end()));
        People.erase(prev(People.end()));
        Res.push_back(make_pair(B,-1));
        tim+=B;
      }
    }
    cout<<tim<<endl;
    for(int i=0;i<Res.size();i++){
      cout<< Res[i].first;
      if(Res[i].second != -1)
        cout<<" "<< Res[i].second;
      cout<<endl;
    }
    if(t)
      cout<<endl;
  }
}
