#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  while(cin>>N){
    string st;
    vector<pair<int,int>> I,F;
    for(int i=1;i<=N;i++){
      cin>>st;
      for(int j=0;j<N;j++){
        if(st[j]=='1'){
          I.push_back(make_pair(i,j+1));
        }
        else if(st[j]=='3'){
          F.push_back(make_pair(i,j+1));
        }
      }
    }
    int mx=INT_MIN;
    for(int i=0;i<I.size();i++){
      int mn=INT_MAX;
      for(int j=0;j<F.size();j++){
        int tmp=abs(I[i].first-F[j].first)+abs(I[i].second-F[j].second);
        mn=min(mn,tmp);
      }
      mx=max(mx,mn);
    }
    printf("%d\n",mx);
  }
}
