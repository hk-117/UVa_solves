#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<int> Clr;
bool isBipart(int &mn,int s){
  int z=0,o=0;
  Clr[s]=0;
  z++;
  queue<int> q;
  q.push(s);
  bool bpt=true;
  while(!q.empty() && bpt){
    int u=q.front();
    q.pop();
    for(int j=0;j<G[u].size();j++){
      int v=G[u][j];
      if(Clr[v]==-1){
        Clr[v]=1-Clr[u];
        if(Clr[v]) o++;
        else z++;
        q.push(v);
      }
      else if(Clr[v]==Clr[u]){
        bpt=false;
        break;
      }
    }
  }
  if(!bpt) return false;
  else{
    mn=min(o,z);
    return true;
  }
}
int main(){
  int V,E,T;
  cin>>T;
  while(T--){
    cin>>V>>E;
    G.assign(V,vector<int>());
    Clr.assign(V,-1);
    int a,b;
    for(int i=1;i<=E;i++){
      cin>>a>>b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    bool bpt=true;
    int mn,cnt=0;
    for(int s=0;s<V && bpt;s++){
      if(Clr[s]!= -1) continue;
      else if(Clr[s]== -1 && G[s].size()==0){
        cnt++;
      }
      else{
        bpt=isBipart(mn,s);
        cnt+=mn;
      }
    }
    if(bpt)
      printf("%d\n",cnt);
    else
      puts("-1");
  }
}
