#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define ms(a,b) memset(a,b,sizeof(a))
#define mx 105
using namespace std;
vector<vector<int>> G(mx);
int status[mx];
void dfs(int u){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!status[v]){
            status[v]=1;
            dfs(v);
        }
    }
}
int main(){
    int n;
    while(cin>>n,n){
        string line;
        cin.ignore();
        while(getline(cin,line),line!="0"){
            stringstream ss(line);
            int u,v;
            ss>>u;
            while(ss>>v,v){
                G[u].push_back(v);
            }
        }
        int sz,svertex;
        cin>>sz;
        R(i,0,sz,1){
            cin>>svertex;
            dfs(svertex);
            int nm= count(status+1,status+n+1,0);
            cout<<nm;
            R(j,1,n+1,1){
                if(!status[j])
                    cout<<" "<<j;
            }
            cout<<endl;
            ms(status,0);
        }
        R(i,1,n+1,1)
            G[i].clear();
    }
}
