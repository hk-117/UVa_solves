#include<stdio.h>
#define R(i,a,b,c) for(i=a;i<b;i+=c)
#define scan(a) scanf("%d",&a)
#define max(a,b) (a)>(b)?(a):(b)
int main(){
    int n,A;
    while(scan(n)==1 && n){
        int i,sum=0,ans=0;
        R(i,0,n,1){
            scan(A);
            sum+=A;
            ans= max(ans,sum);
            if(sum<0) sum=0;
        }
        if(ans<=0)
            puts("Losing streak.");
        else{
            printf("The maximum winning streak is %d.\n",ans);
        }
    }
}
