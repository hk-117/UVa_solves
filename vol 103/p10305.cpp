#include<bits/stdc++.h>
using namespace std;
bitset<105> visited;
vector<int> lst;
vector<int> Graph[101];
void topsort(int u){
  visited[u]=1;
  for(int j=0;j<Graph[u].size();j++){
    int v=Graph[u][j];
    if(!visited[v]){
      topsort(v);
    }
  }
  lst.push_back(u);
}
int main(){
  int N,M;
  while(cin>>N>>M,N||M){
    int u,v;
    for(int i=0;i<101;i++) Graph[i].clear();
    lst.clear();
    visited.reset();
    for(int i=1;i<=M;i++){
      cin>>u>>v;
      Graph[u].push_back(v);
    }
    for(int i=1;i<=N;i++){
      if(!visited[i])
        topsort(i);
    }
    for(int i=(int)lst.size()-1;i>=0;i--){
      printf("%d",lst[i]);
      if(i)
        printf(" ");
    }
    puts("");
  }
}
