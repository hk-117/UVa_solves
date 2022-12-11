#include<bits/stdc++.h>
using namespace std;
vector<set<int>> G(11);
vector<int> walk;
bitset<11>visited;
int l,cnt;
void dfs(int u,int dist){
    visited[u]=1;
    walk.push_back(u);
    if(dist==l){
        int i;
        cnt++;
        cout<< "(";
        for(i=0;i<walk.size()-1;i++){
            cout<<walk[i]<<",";
        }
        cout<<walk[i]<<")"<<endl;
        return;
    }
    for(auto it=G[u].begin();it!=G[u].end();it++){
        int v=*it;
        if(!visited[v]){
            dist++;
            dfs(v,dist);
            dist--;
            visited[v]=0;
            walk.pop_back();
        }
    }
}
int main(){
    int n,tc=0;
    while(cin>>n>>l){
        if(tc++)
            cout<<endl;
        int inp;
        for(int i=1;i<=10;i++)
            G[i].clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>inp;
                if(inp==1){
                    G[i].insert(j);
                    G[j].insert(i);
                }
            }
        }
        cin>>inp;
        visited.reset();
        cnt=0;
        walk.clear();
        dfs(1,0);
        if(cnt==0)
            cout<<"no walk of length "<<l<<endl;
    }
}
