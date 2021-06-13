#include<stdio.h>
#define MAX 105
int N;
char B[MAX][MAX];
int hasHorizonX(int horline,int start){
    int i,a=0;
    for(i=start+1;i<N;i++){
        if(B[horline][i]=='x'){
            a=1;
            B[horline][i]='.';
        }
        else if(B[horline][i]=='@')
            B[horline][i]='.';
        else
            break;
    }
    return a;
}
int hasVertX(int start,int vertline){
    int i,a=0;
    for(i=start+1;i<N;i++){
        if(B[i][vertline]=='x'){
            a=1;
            B[i][vertline]='.';
        }
        else if(B[i][vertline]=='@')
            B[i][vertline]='.';
        else
            break;
    }
    return a;
}
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int i,j,res=0,h,r;
        scanf("%d",&N);
        getchar();
        for(i=0;i<N;i++){
            scanf("%s",B[i]);
        }
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(B[i][j]!='.'){
                    if(B[i][j]=='x'){
                        res++;
                        h=hasHorizonX(i,j);
                        if(!h)
                            r=hasVertX(i,j);
                    }
                    else{
                        if(hasHorizonX(i,j)){
                            res++;
                        }
                        else{
                            if(hasVertX(i,j))
                                res++;
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n",++tc,res);
    }
}
