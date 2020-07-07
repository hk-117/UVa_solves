#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define mx 105
#define ms(a,b) memset(a,b,sizeof(a));
using namespace std;
int status[105],visit;
vector<vector<int>> G(mx);
void dfs(int start,int block){
    if(start>0)
        visit=1;
    if(start==block && block!=0){
        status[start]=1;
        return;
    }
    status[start]=1;
    R(j,0,(int)G[start].size(),1){
        int v= G[start][j];
        if(!status[v]){
            dfs(v,block);
        }
    }
}
void prntBorder(int n){
    R(i,0,2*n+1,1){
        if(i==0 || i== (2*n))
            putchar('+');
        else
            putchar('-');
    }
    puts("");
}
int main(){
    int t,tc=0;
    cin>>t;
    while(t--){
        tc++;
        int n;
        scanf("%d",&n);
        int inp;
        char dmntr[n][n];
        map<int,bool> disc;
        R(i,0,n,1)
            ms(dmntr[i],'N');
        R(i,0,n,1){
            R(j,0,n,1){
                scanf("%d",&inp);
                if(inp && i!=j){
                    G[i].push_back(j);
                }
            }
        }
        R(i,0,n,1){
            dfs(0,i);
            R(j,0,n,1){
                if(i==0 && status[j]){
                    dmntr[i][j]='Y';
                    dmntr[j][j]='Y';
                }
                else if(i==0 && !status[j]){
                    dmntr[i][j]='N';
                    disc[j]=true;
                }
                else if(!status[j] && i!=0 && visit && !disc[j]){
                    dmntr[i][j]='Y';
                }
            }
            visit=0;
            ms(status,0);
        }
        printf("Case %d:\n",tc);
        prntBorder(n);
        R(i,0,n,1){
            R(j,0,n,1){
                putchar('|');
                if(dmntr[i][j]=='Y'){
                    putchar(dmntr[i][j]);
                }
                else{
                    putchar(dmntr[i][j]);
                }
            }
            puts("|");
            prntBorder(n);
        }
        R(i,0,n,1){
            G[i].clear();
        }
    }
}
