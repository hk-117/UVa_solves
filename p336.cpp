#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>G;
map<int,int> dist,visited;
int main(){
  int NC,Src,ttl,tc=0;
  while(scanf("%d",&NC)==1 && NC){
    int a,b;
    for(int i=0;i<NC;i++){
      scanf("%d %d",&a,&b);
      G[a].push_back(b);
      G[b].push_back(a);
      visited[a]=-1;
      visited[b]=-1;
    }
    int nRcbl;
    while(scanf("%d %d",&Src,&ttl)==2 && (Src||ttl)){
      dist.clear();
      for(auto it=visited.begin();it!=visited.end();it++) it->second=-1;
      printf("Case %d: ",++tc);
      nRcbl=0;
      dist[Src]=0;
      visited[Src]=1;
      queue<int>q;
      q.push(Src);
      while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int j=0;j<G[u].size();j++){
          int v=G[u][j];
          if(visited[v]==-1){
            visited[v]=1;
            dist[v]=dist[u]+1;
            q.push(v);
            if(dist[v]>ttl)
              nRcbl++;
          }
        }
      }
      for(auto it=visited.begin();it!=visited.end();it++){
        if(it->second == -1) nRcbl++;
      }
      printf("%d nodes not reachable from node %d with TTL = %d.\n",nRcbl,Src,ttl);
    }
    G.clear();
    visited.clear();
  }
}
