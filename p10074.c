#include<stdio.h>
#define mx 100000
#define max(a,b) (a)>(b)?(a):(b)
int Mat[105][105];
int main(){
    int m,n;
    while(scanf("%d %d",&n,&m)==2 && (n||m)){
        int i,j,k,l,maxSub,subRect;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&Mat[i][j]);
                if(Mat[i][j]==0){
                    Mat[i][j]=1;
                }
                else{
                    Mat[i][j]=-mx;
                }
                if(i>0) Mat[i][j] += Mat[i-1][j];
                if(j>0) Mat[i][j] += Mat[i][j-1];
                if(j>0 && i>0) Mat[i][j] -= Mat[i-1][j-1];
            }
        }
        maxSub= -mx;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                for(k=i;k<n;k++){
                    for(l=j;l<m;l++){
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
