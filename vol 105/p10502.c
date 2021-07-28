#include<stdio.h>

int n,m;
char Board[105][105];
int findQuad(int,int);
int isQuad(int,int,int,int);

int main(){
    int i,j;
    while(scanf("%d",&n)==1 && n){
        int quad=0;
        scanf("%d",&m);
        getchar();
        for(i=0;i<n;i++){
            scanf("%s",Board[i]);
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(Board[i][j]=='1'){
                    quad+= findQuad(i,j); 
                }
            }
        }
        printf("%d\n",quad);
    }
}

int findQuad(int sti,int stj){
    int i,j,quad=0;
    for(i=sti;i<n;i++){
        for(j=stj;j<m;j++){
            if(isQuad(sti,stj,i,j))
                quad++;
            else
                break;
        }
    }
    return quad;
}

int isQuad(int sti,int stj,int r,int c){
    int i,j;
    for(i=sti;i<=r;i++){
        for(j=stj;j<=c;j++){
            if(Board[i][j]=='0')
                return 0;
        }
    }
    return 1;
}
