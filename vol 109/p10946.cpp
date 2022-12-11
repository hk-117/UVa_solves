#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1, 0};
int dy[]={0,1, 0,-1};
int r,c;
char G[55][55];
int floodfill(int x,int y,char c1,char c2){
    if(x<0||x>=r||y<0||y>=c) return 0;
    if(G[x][y]!= c1) return 0;
    G[x][y]=c2;
    int ans=1;
    for(int d=0;d<4;d++)
        ans+= floodfill(x+dx[d],y+dy[d],c1,c2);
    return ans;
}
bool cmp(pair<int,char>a,pair<int,char>b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}
int main(){
    int i,j,tc=0;
    while(scanf("%d %d",&r,&c)==2 && (r||c)){
        vector<pair<int,char>> Cnt;
        int tmp;
        getchar();
        for(i=0;i<r;i++){
            scanf("%s",G[i]);
            getchar();
        }
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(G[i][j]!='.'){
                    char cr=G[i][j];
                    tmp=floodfill(i,j,cr,'.');
                    Cnt.push_back(make_pair(tmp,cr));
                }
            }
        }
        sort(Cnt.begin(),Cnt.end(),cmp);
        printf("Problem %d:\n",++tc);
        for(int i=0;i<Cnt.size();i++){
            printf("%c %d\n",Cnt[i].second,Cnt[i].first);
        }
    }
}
