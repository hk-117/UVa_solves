#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
vector<int> G[25];
int mx=-1;
map<pair<int,int>,bool> visited;
void dfs(int u,int pLen){
    pLen++;
    R(i,0,(int)G[u].size(),1){
        int v=G[u][i];
        if(!visited[make_pair(u,v)] && !visited[make_pair(v,u)]){
            visited[make_pair(u,v)]=true;
            dfs(v,pLen);
            visited[make_pair(u,v)]=false;
        }
    }
    mx=max(mx,pLen);
}
int main(){
    int n,m;
    while(cin>>n>>m,n||m){
        int a,b;
        R(i,0,m,1){
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        mx=-1;
        for(int i=0;i<n;i++){
            visited.clear();
            dfs(i,0);
        }
        cout<< mx-1 <<endl;
        for(int i=0;i<25;i++)
            G[i].clear();
    }
}
