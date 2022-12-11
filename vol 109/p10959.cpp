#include<bits/stdc++.h>
using namespace std;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int P,D;
    scanf("%d %d",&P,&D);
    vector<int> G[P];
    int u,v;
    for(int i=0;i<D;i++){
      scanf("%d %d",&u,&v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    vector<int> dist(P,-1);
    dist[0]=0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      int u=q.front();
      q.pop();
      for(int j=0;j<G[u].size();j++){
        int v=G[u][j];
        if(dist[v]==-1){
          dist[v]=dist[u]+1;
          q.push(v);
        }
      }
    }
    for(int i=1;i<P;i++){
      printf("%d\n",dist[i]);
    }
    if(T)
      putchar('\n');
  }
}
