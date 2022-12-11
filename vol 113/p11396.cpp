#include<bits/stdc++.h>
using namespace std;
int main(){
  int V;
  while(cin>>V,V){
    vector<int> G[V+1],Clr(V+1,-1);
    int a,b;
    while(cin>>a>>b,a||b){
      G[a].push_back(b);
      G[b].push_back(a);
    }
    Clr[1]=0;
    queue<int> q;
    q.push(1);
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
      puts("YES");
    else
      puts("NO");
  }
}
