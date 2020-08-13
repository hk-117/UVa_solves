#include<stdio.h>
#include<math.h>
#include<limits.h>
int D[550];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int r,i,j,sum,min=INT_MAX;
        scanf("%d",&r);
        for(i=0;i<r;i++){
            scanf("%d",&D[i]);
        }
        for(i=0;i<r;i++){
            sum=0;
            for(j=0;j<r;j++){
                if(i==j)
                    continue;
                sum += abs(D[i]-D[j]);
            }
            min= min>sum ? sum : min;
        }
        printf("%d\n",min);
    }
}
