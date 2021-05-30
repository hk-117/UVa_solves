#include<stdio.h>
double Avg(int *A){
    int sum,i;
    if(A[0]==0)
        return 0;
    sum=0;
    for(i=1;i<=A[0];i++){
        sum+=A[i];
    }
    return (double)sum/(double)A[0];
}
int main(){
    int S[35],i,U[35],D[35],isup,isdown,ismiddle,input;
    while(scanf("%d",&input)==1 && input){
        int upsize,downsize,middlesize;
        S[0]=1;
        S[1]=input;
        while(scanf("%d",&input)==1 && input){
            S[0]++;
            S[S[0]]=input;
        }
        isup=0;
        isdown=0;
        ismiddle=1;
        upsize=0;
        downsize=0;
        middlesize=1;
        U[0]=0;
        D[0]=0;
        for(i=2;i<=S[0];i++){
            if(S[i]>S[i-1]){
                isup=1;
                if(ismiddle && !isdown){
                    upsize+=middlesize;
                    middlesize=0;
                    ismiddle=0;
                }
                else if(isdown){
                    D[0]++;
                    D[D[0]]=downsize;
                    downsize=0;
                    isdown=0;
                    upsize++;
                }
                else{
                    upsize++;
                }
            }
            else if(S[i]<S[i-1]){
                isdown=1;
                if(ismiddle && !isup){
                    downsize+=middlesize;
                    middlesize=0;
                    ismiddle=0;
                }
                else if(isup){
                    U[0]++;
                    U[U[0]]=upsize;
                    upsize=0;
                    isup=0;
                    downsize++;
                }
                else{
                    downsize++;
                }
            }
            else{
                if(isdown){
                    downsize++;
                }
                else if(isup){
                    upsize++;
                }
                else{
                    middlesize++;
                }
            }
        }
        if(isup){
            U[0]++;
            U[U[0]]=upsize;
        }
        else if(isdown){
            D[0]++;
            D[D[0]]=downsize;
        }
        printf("Nr values = %d:  %.6lf %.6lf\n",S[0],Avg(U),Avg(D));
    }
}
