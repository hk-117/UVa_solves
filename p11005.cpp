#include<bits/stdc++.h>
using namespace std;
string digits="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int Pr[150];
int calcExpns(string N,int bs){
  int nm= atoi(N.c_str()),ans=0;
  while(nm>0){
    ans+= Pr[digits[nm%bs]];
    nm/=bs;
  }
  return ans;
}
int main(){
  int T,tc=0;
  cin>>T;
  while(T--){
    for(int i=0;i<36;i++)
      cin>>Pr[digits[i]];
    int Q,E,mx;
    cin>>Q;
    string N;
    cout<<"Case "<< ++tc <<":"<<endl;
    while(Q--){
      map<int,vector<int>> expns;
      cin>>N;
      mx=-1;
      for(int bs=2;bs<=36;bs++){
        E=calcExpns(N,bs);
        expns[E].push_back(bs);
      }
      cout<<"Cheapest base(s) for number "<<N<<":";
      auto it=expns.begin();
      for(int i=0;i<it->second.size();i++){
        cout<<" "<< it->second[i];
      }
      cout<<endl;
    }
    if(T)
      cout<<endl;
  }
}
