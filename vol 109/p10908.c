#include<stdio.h>

int N,M,Q;
char Grid[105][105];
int validRing(int,int,int);

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int i,j;
        scanf("%d %d %d",&N,&M,&Q);
        getchar();
        for(i=0;i<N;i++){
            scanf("%s",Grid[i]);
        }
        printf("%d %d %d\n",N,M,Q);
        while(Q--){
            int r,c,side=1;
            scanf("%d %d",&r,&c);
            while(validRing(r,c,side)){
                side++;
            }
            printf("%d\n",2*(side-1)+1);
        }
    }
}

int validRing(int r,int c,int dist){
    int i,j,sti,stj,eni,enj,far;
    char ch=Grid[r][c];
    sti=r-dist;
    stj=c-dist;
    far= 2*dist +1;
    eni=sti+far;
    enj=stj+far;
    if(sti<0||stj<0||eni>N||enj>M)
        return 0;
    for(i=sti;i<eni;i++){
        for(j=stj;j<enj;j++){
            if(Grid[i][j]!=ch)
                return 0;
        }
    }
    return 1;
}
