#include<stdio.h>
#include<string.h>
int V[105],G[105];
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,m,u,v,i,last,total=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&V[i]);
        }
        memset(G,0,sizeof G);
        for(i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            if(V[v]>V[G[u]]){
                G[u]=v;
            }
        }
        u=0;
        total+=V[u];
        while(G[u]!=0){
            total+=V[G[u]];
            last=G[u];
            u=G[u];
        }

        printf("Case %d: %d %d\n",++tc,total,last);
    }
}
