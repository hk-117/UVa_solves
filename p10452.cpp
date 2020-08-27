#include<cstdio>
#include<cstring>
#define R(i,a,b,c) for(i=a;i<b;i+=c)
using namespace std;
char G[9][9];
int n,m;
char path[]="@IEHOVA#";
int px[]={-1,0,0},py[]={0,-1,1};
int isValid(int x,int y){
    if(x>=m || y>=n)
        return 0;
    return 1;
}
void findPath(int x,int y,int len){
    len++;
    if(isValid(x+px[0],y+py[0]) && path[len]==G[x+px[0]][y+py[0]]){
        if(len==7){
            puts("forth");
            return;
        }
        else{
            printf("forth ");
            findPath(x+px[0],y+py[0],len);
        }
    }
    else if(isValid(x+px[1],y+py[1]) && path[len]==G[x+px[1]][y+py[1]]){
        if(len==7){
            puts("left");
            return;
        }
        else{
            printf("left ");
            findPath(x+px[1],y+py[1],len);
        }
    }
    else if(isValid(x+px[2],y+py[2]) && path[len]==G[x+px[2]][y+py[2]]){
        if(len==7){
            puts("right");
            return;
        }
        else{
            printf("right ");
            findPath(x+px[2],y+py[2],len);
        }
    }
}
int main(){
    int t,pos,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&m,&n);
        R(i,0,m,1){
            scanf("%s",G[i]);
        }
        pos=strchr(G[m-1],'@')-G[m-1];
        findPath(m-1,pos,0);
    }
}
