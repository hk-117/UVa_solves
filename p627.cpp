#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
void printPath(vector<int> &p,int en,int st){
  if(en==st){
    printf("%d",st);
    return;
  }
  printPath(p,p[en],st);
  printf(" %d",en);
}
int main(){
  int N;
  while(cin>>N){
    printf("-----\n");
    vector<int> G[N+1];
    int u,v;
    string nums;
    R(i,0,N,1){
      cin>>u>>nums;
      nums.erase(nums.begin());
      if(nums.size()){
        for(int i=0;i<nums.size();i++)
          if(nums[i]==',') nums[i]=' ';
        stringstream ss(nums);
        while(ss>>v){
          G[u].push_back(v);
        }
      }
    }
    int M,st,en;
    cin>>M;
    while(M--){
      cin>>st>>en;
      vector<int> p(N+1),dist(N+1,-1);
      queue<int> q;
      q.push(st);
      dist[st]=0;
      while(!q.empty()){
        u=q.front();q.pop();
        for(int j=0;j<G[u].size();j++){
          v=G[u][j];
          if(dist[v]==-1){
            dist[v]=dist[u]+1;
            p[v]=u;
            q.push(v);
          }
        }
      }
      if(dist[en]==-1) puts("connection impossible");
      else{
        printPath(p,en,st);
        printf("\n");
      }
    }
  }
}
