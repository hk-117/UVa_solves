#include<bits/stdc++.h>
using namespace std;
vector<int>G[105];
vector <int> Vals(105);
int last=0,total=0;
void traverse(int u){
    total+=Vals[u];
    if(!G[u].size()){
        last=u;
        return;
    }
    traverse(G[u][0]);
}
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&Vals[i]);
        }
        for(int i=0;i<n;i++)
            G[i].clear();
        int u,v;
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            if(!G[u].size()){
                G[u].push_back(v);
            }
            else{
                if(Vals[G[u][0]]<Vals[v]){
                    G[u].insert(G[u].begin(),v);
                }
                else{
                    G[u].push_back(v);
                }
            }
        }
        last=0;
        total=0;
        traverse(0);
        printf("Case %d: %d %d\n",++tc,total,last);
    }
}
