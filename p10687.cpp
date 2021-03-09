#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;
typedef struct{
    int pos,x,y;
    double d;
} Point;
vector<vector<int>> Graph;
double dist(pair<int,int> a,pair<int ,int > b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
bool fnc(Point a,Point b){
    if(fabs(a.d-b.d) <eps){
        if(a.x==b.x){
            return a.y<b.y;
        }
        else{
            return a.x<b.x;
        }
    }
    return a.d<b.d;
}
bitset<1005> visited;
void dfs(int u){
    visited[u]=1;
    for(int i=0;i<Graph[u].size();i++){
        int v=Graph[u][i];
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
    int N;
    while(scanf("%d",&N)==1 && N){
        Graph.assign(N,vector<int>());
        vector<pair<int,int>> Pairs(N);
        for(int i=0;i<N;i++){
            scanf("%d %d",&Pairs[i].first,&Pairs[i].second);
        }
        if(N<=3){
            puts("All stations are reachable.");
            continue;
        }
        double ds;
        for(int i=0;i<N;i++){
            Point tmp,sml,tndsml;
            sml.d=INT_MAX;
            tndsml.d=INT_MAX;
            tndsml.y=10005;
            sml.x=tndsml.y;
            tndsml.x=sml.x;
            sml.y=tndsml.x;
            for(int j=0;j<N;j++){
                if(i!=j){
                    ds=dist(Pairs[i],Pairs[j]);
                    tmp.pos=j;
                    tmp.x=Pairs[j].first;
                    tmp.y=Pairs[j].second;
                    tmp.d=ds;
                    if(fnc(tmp,sml)){
                        tndsml=sml;
                        sml=tmp;
                    }
                    else{
                        if(fnc(tmp,tndsml)){
                            tndsml=tmp;
                        }
                    }
                }
            }
            Graph[i].push_back(sml.pos);
            Graph[i].push_back(tndsml.pos);
        }
        visited.reset();
        dfs(0);
        bool reached=true;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                reached=false;
                break;
            }
        }
        if(reached)
            puts("All stations are reachable.");
        else
            puts("There are stations that are unreachable.");
    }
}
