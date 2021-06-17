#include<cstdio>
#include<cstring>
using namespace std;
int x[]={0,0,-1,1},y[]={-1,1,0,0};
char Grid[55][55];
int ans=0,W,H;
int isvalid(int i,int j){
    if(i>H || i<0 || j>W || j<0)
        return 0;
    return 1;
}
int istrap(int i,int j){
    int idx;
    for(idx=0;idx<=3;idx++){
        if(isvalid(i+x[idx],j+y[idx]))
            if(Grid[i+x[idx]][j+y[idx]]=='T')
                return 1;
    }
    return 0;
}
void play(int pi,int pj){
    int i;
    if(!isvalid(pi,pj)){
        return;
    }
    else if(Grid[pi][pj]=='#')
        return;
    else if(Grid[pi][pj]=='G'){
        ans++;
        Grid[pi][pj]='#';
    }
    else if(Grid[pi][pj]=='.'){
        Grid[pi][pj]='#';
    }
    if(istrap(pi,pj)){
        return;
    }
    else{
        for(i=0;i<=3;i++){
            play(pi+x[i],pj+y[i]);
        }
    }
}
int main(){
    int i;
    while(scanf("%d %d",&W,&H)==2){
        int pi,pj;
        char *ptr;
        getchar();
        for(i=0;i<H;i++){
            scanf("%s",Grid[i]);
            ptr=strchr(Grid[i],'P');
            if(ptr!=NULL){
                pi=i;
                pj=ptr-Grid[i];
                Grid[pi][pj]='.';
            }
        }
        ans=0;
        play(pi,pj);
        printf("%d\n",ans);
    }
}
