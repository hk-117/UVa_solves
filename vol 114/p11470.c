#include<stdio.h>
int sq[11][11],R[10];
int main(){
    int n,tc=0;
    while(scanf("%d",&n)==1 && n){
        int i,j,k;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                scanf("%d",&sq[i][j]);
            }
        }
        for(k=0;k<(n/2+(n%2));k++){
            int sum=0;
            for(i=k;i<n-k;i++){
                for(j=k;j<n-k;j++){
                    sum+= sq[i][j];
                }
            }
            R[k]=sum;
        }
        printf("Case %d:",++tc);
        for(i=0;i<k-1;i++){
            printf(" %d",R[i]-R[i+1]);
        }
        printf(" %d\n",R[i]);
    }
}
