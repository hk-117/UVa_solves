#include<bits/stdc++.h>
using namespace std;
vector<string> NMS;
vector<int>G[101],indeg(101),lst;
map<string,int>I;
int N;
void kahn(){
  priority_queue<int,vector<int>,greater<int>> Zdeg;
  for(int i=1;i<=N;i++){
    if(indeg[i]==0)
      Zdeg.push(i);
  }
  while(!Zdeg.empty()){
    int u= Zdeg.top();
    lst.push_back(u);
    Zdeg.pop();
    for(int i=0;i<G[u].size();i++){
      indeg[G[u][i]]--;
      if(indeg[G[u][i]]==0)
        Zdeg.push(G[u][i]);
    }
  }
}
int main(){
  int M,tc=0;
  string name;
  while(cin>>N){
    I.clear();
    for(int i=0;i<101;i++) G[i].clear();
    indeg.assign(101,0);
    lst.clear();
    NMS.clear();
    for(int i=1;i<=N;i++){
      cin>>name;
      NMS.push_back(name);
      I[name]=i;
    }
    cin>>M;
    string n1,n2;
    for(int i=1;i<=M;i++){
      cin>>n1>>n2;
      G[I[n1]].push_back(I[n2]);
      indeg[I[n2]]++;
    }
    kahn();
    printf("Case #%d: Dilbert should drink beverages in this order:",++tc);
    for(int i=0;i<lst.size();i++){
      printf(" %s",NMS[lst[i]-1].data());
    }
    printf(".\n\n");
  }
}
