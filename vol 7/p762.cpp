#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
  int Lnk;
  bool nl=false;
  while(cin>>Lnk){
    if(nl) putchar('\n');
    else{
      nl=true;
    }
    map<string,int> Mpr;
    vector<int> G[2*Lnk +1];
    vector<string> revMpr(2*Lnk +1);
    string a,b;
    int u,v,cnt=1;
    R(i,0,Lnk,1){
      cin>>a>>b;
      if(Mpr[a]>0){
        u=Mpr[a];
      }
      else{
        Mpr[a]=cnt;
        cnt++;
        u=Mpr[a];
        revMpr[u]=a;
      }
      if(Mpr[b]>0){
        v=Mpr[b];
      }
      else{
        Mpr[b]=cnt;
        cnt++;
        v=Mpr[b];
        revMpr[v]=b;
      }
      G[u].push_back(v);
      G[v].push_back(u);
    }
    cin>>a>>b;
    int st,en;
    st=Mpr[a];
    en=Mpr[b];
    vector<int> Parent(cnt,0),dist(cnt,-1);
    queue<int> q;
    dist[st]=0;
    q.push(st);
    while(!q.empty()){
      u=q.front();q.pop();
      for(int j=0;j<G[u].size();j++){
        v=G[u][j];
        if(dist[v]==-1){
          dist[v]=dist[u]+1;
          q.push(v);
          Parent[v]=u;
        }
      }
    }
    if(dist[en]==-1 || Mpr[a]==0 || Mpr[b]==0)
      puts("No route");
    else{
      stack<int> Path;
      Path.push(en);
      while(Parent[en]!=st){
        Path.push(Parent[en]);
        en=Parent[en];
      }
      while(!Path.empty()){
        cout<< revMpr[st] <<" "<<revMpr[Path.top()]<<endl;
        st=Path.top();
        Path.pop();
      }
    }
  }
}
