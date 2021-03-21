#include<stdio.h>
char Grid[105][105];
int r,c;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int isValid(int x,int y){
    if(x<0||x>=r||y<0||y>=c)
        return 0;
    return 1;
}
int main(){
    int i,j;
    while(scanf("%d %d",&r,&c)==2 && (r||c)){
        int cnt=0;
        getchar();
        for(i=0;i<r;i++){
            scanf("%s",Grid[i]);
            getchar();
        }
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(Grid[i][j]=='*'){
                    int flg=0,k,x,y;
                    for(k=0;k<8 && !flg;k++){
                        x=i+dx[k];
                        y=j+dy[k];
                        if(isValid(x,y) && Grid[x][y]=='*'){
                            flg=1;
                        }
                    }
                    if(!flg){
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
}
