#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
  int T,tc=0;
  cin>>T;
  puts("SHIPPING ROUTES OUTPUT\n");
  while(T--){
    printf("DATA SET  %d\n\n",++tc);
    int M,N,P;
    cin>>M>>N>>P;
    vector<int> G[M+1];
    map<string,int> Mpr;
    string a,b,name;
    R(i,1,M+1,1){
      cin>>name;
      Mpr[name]=i;
    }
    int u,v;
    R(i,0,N,1){
      cin>>a>>b;
      u=Mpr[a];
      v=Mpr[b];
      G[u].push_back(v);
      G[v].push_back(u);
    }
    int sz,st,en;
    while(P--){
      cin>>sz>>a>>b;
      st=Mpr[a];en=Mpr[b];
      vector<int> dist(M+1,-1);
      queue<int> q;
      q.push(st);
      dist[st]=0;
      while(!q.empty()){
        u=q.front();q.pop();
        for(int j=0;j<G[u].size();j++){
          v=G[u][j];
          if(dist[v]==-1){
            dist[v]=dist[u]+1;
            q.push(v);
          }
        }
      }
      if(dist[en]==-1) puts("NO SHIPMENT POSSIBLE");
      else{
        printf("$%d\n",sz*dist[en]*100);
      }
    }
    puts("");
  }
  puts("END OF OUTPUT");
}
