#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int I[1050];
int cmp(const void* a, const void* b){
    int *aa,*bb;
    aa= (int *)a;
    bb= (int *)b;
    return *aa-*bb;
}
int main(){
    int n,m,tc=0;
    while(scanf("%d",&n)==1 && n){
        int i,j,diff,pdiff=INT_MAX,clos,sum,q;
        for(i=0;i<n;i++){
            scanf("%d",&I[i]);
        }
        scanf("%d",&m);
        qsort(I,n,sizeof(int),cmp);
        printf("Case %d:\n",++tc);
        while(m--){
            scanf("%d",&q);
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(i==j)
                        continue;
                    sum= I[i]+I[j];
                    diff=abs(sum - q);
                    if(diff < pdiff){
                        pdiff= diff;
                        clos=sum;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n",q,clos);
            pdiff=INT_MAX;
        }
    }
}
