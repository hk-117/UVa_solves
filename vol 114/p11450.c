#include<stdio.h>
#include<string.h>
#define mx 1000000000
int M,C,price[25][25],m[210][25];
int max(int a,int b){
    return a>b ? a:b;
}
int shop(int tk,int g){
    int ans=-1,model;
    if(tk<0){
        return -mx;
    }
    if(g==C) return M-tk;
    if(m[tk][g] != -1) return m[tk][g];
    for(model =1 ;model <= price[g][0];model++){
        ans= max(ans,shop(tk-price[g][model],g+1));
    }
    m[tk][g]=ans;
    return ans;
}
int main(){
    int i,j,tc,ans;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d %d",&M,&C);
        for(i=0;i<C;i++){
            scanf("%d",&price[i][0]);
            for(j=1;j<=price[i][0];j++) scanf("%d",&price[i][j]);
        }
        memset(m,-1,sizeof m);
        ans= shop(M,0);
        if(ans<0)
            puts("no solution");
        else
            printf("%d\n",ans);
    }
}
