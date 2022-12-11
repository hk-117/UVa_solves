#include<cstdio>
using namespace std;
int PPL[55],N,X;
void markPpl(int interval){
    int i,j;
    j=0;
    for(i=1;i<=N;i++){
        if(PPL[i]!=-1){
            j++;
            if(j%interval==0){
                PPL[0]--;
                PPL[i]=-1;
                if(PPL[0]==X)
                    return;
            }
        }
    }
}
int main(){
    int tc=0;
    while(scanf("%d %d",&N,&X)==2){
        int i,j,tmp;
        PPL[0]=N;
        for(i=1;i<=N;i++) PPL[i]=i;
        for(j=1;j<=20;j++){
            scanf("%d",&tmp);
            if(PPL[0]>X){
                markPpl(tmp);
            }
        }
        j=1;
        i=0;
        printf("Selection #%d\n",++tc);
        while(i<PPL[0]){
            if(PPL[j]!=-1){
                if(!i)
                    printf("%d",PPL[j]);
                else
                    printf(" %d",PPL[j]);
                i++;
            }
            j++;
        }
        puts("\n");
    }
}
