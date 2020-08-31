#include<stdio.h>
#include<string.h>
#define mx 100000
#define max(a,b) (a)>(b)?(a):(b)
int Mat[105][105];
int main(){
    int b,n,t;
    scanf("%d",&t);
    while(t--){
        int i,j,k,l,maxSub,subRect,r1,c1,r2,c2;
        scanf("%d",&n);
        scanf("%d",&b);
        memset(Mat,0,sizeof Mat);
        for(i=1;i<=b;i++){
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            for(j=r1-1;j<r2;j++){
                for(k=c1-1;k<c2;k++){
                    Mat[j][k]= -mx;
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(Mat[i][j]==0){
                    Mat[i][j]=1;
                }
                if(i>0) Mat[i][j] += Mat[i-1][j];
                if(j>0) Mat[i][j] += Mat[i][j-1];
                if(j>0 && i>0) Mat[i][j] -= Mat[i-1][j-1];
            }
        }
        maxSub= -mx;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=i;k<n;k++){
                    for(l=j;l<n;l++){
                        subRect= Mat[k][l];
                        if(i>0) subRect -= Mat[i-1][l];
                        if(j>0) subRect -= Mat[k][j-1];
                        if(i>0 && j>0) subRect += Mat[i-1][j-1];
                        maxSub= max(maxSub,subRect);
                    }
                }
            }
        }
        if(maxSub <0)
            puts("0");
        else
            printf("%d\n",maxSub);
    }
}
