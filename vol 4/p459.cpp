#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
typedef vector<vector<int>> Graph;
bool status[30]={false};
void dfs(int crnt,Graph &G){
    status[crnt]=true;
    R(i,0,(int)G[crnt].size(),1){
        int nxt= G[crnt][i];
        if(!status[nxt]){
            dfs(nxt,G);
        }
    }
}
int main(){
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        int sz;
        char large;
        cin>>large;
        sz= large-'A'+1;
        Graph G(sz);
        string inp;
        cin.ignore();
        while(getline(cin,inp),inp.size()){
            G[inp[0]-'A'].push_back(inp[1]-'A');
            G[inp[1]-'A'].push_back(inp[0]-'A');
        }
        int CC=0;
        R(i,0,sz,1){
            if(!status[i]){
                CC++;
                dfs(i,G);
            }
        }
        cout<<CC<<endl;
        if(tc)
            cout<<endl;
        ms(status,false);
    }
}
