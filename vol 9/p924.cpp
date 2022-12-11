#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
  int E;
  while(cin>>E){
    vector<int> G[E];
    int N,tmp;
    R(i,0,E,1){
      cin>>N;
      R(j,0,N,1){
        cin>>tmp;
        G[i].push_back(tmp);
      }
    }
    int T;
    cin>>T;
    while(T--){
      cin>>tmp;
      int mx=0;
      queue<int> q;
      vector<int> dist(E,-1),cnt(E,0);
      dist[tmp]=0;
      q.push(tmp);
      while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int j=0;j<G[u].size();j++){
          int v= G[u][j];
          if(dist[v]==-1){
            dist[v]=dist[u]+1;
            cnt[dist[v]]++;
            mx=max(mx,cnt[dist[v]]);
            q.push(v);
          }
        }
      }
      if(mx==0) puts("0");
      else{
        int D;
        for(int i=0;i<E;i++){
          if(cnt[i]==mx){
            D=i;
            break;
          }
        }
        printf("%d %d\n",mx,D);
      }
    }
  }
}
