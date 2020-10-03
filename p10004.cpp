#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  while(cin>>N,N){
    cin>>M;
    vector<int> G[N],Clr(N,-1);
    int a,b;
    for(int i=0;i<M;i++){
      cin>>a>>b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    Clr[0]=0;
    queue<int> q;
    q.push(0);
    bool bpt=true;
    while(!q.empty() && bpt){
      int u=q.front();
      q.pop();
      for(int j=0;j<G[u].size();j++){
        int v=G[u][j];
        if(Clr[v]==-1){
          Clr[v]=1-Clr[u];
          q.push(v);
        }
        else if(Clr[v]==Clr[u]){
          bpt=false;
          break;
        }
      }
    }
    if(bpt)
      puts("BICOLORABLE.");
    else
      puts("NOT BICOLORABLE.");
  }
}
