#include<cstdio>
using namespace std;
typedef struct{
    int x,y;
} Point;
int Dx[]={-1,-1,0,1,1,1,0,-1},Dy[]={0,-1,-1,-1,0,1,1,1},Flat[3][3];
int main(){
    int Dir;
    Point Cur,tmp;
    while(scanf("%d",&Cur.x)==1 && (Cur.x!=-1)){
        int i,j,Status,found=0;
        scanf("%d %d",&Cur.y,&Dir);
        Flat[1][1]=1;
        for(i=1;i<=8;i++){
            scanf("%d %d %d",&tmp.x,&tmp.y,&Status);
            Flat[1+tmp.y-Cur.y][1+tmp.x-Cur.x]=Status;
        }
        for(i=0;i<3;i++){
            int tmp=Flat[0][i];
            Flat[0][i]=Flat[2][i];
            Flat[2][i]=tmp;
        }
        Cur.x=1;
        Cur.y=1;
        for(i=1;i<=8;i++){
            int pos=(Dir+i+5)%8;
            int nx=Cur.x+Dx[pos],ny=Cur.y+Dy[pos];
            if(Flat[nx][ny]!=0){
                found=1;
                printf("%d\n",pos);
                break;
            }
        }
        if(!found)
            printf("%d\n",Dir);
    }
}
