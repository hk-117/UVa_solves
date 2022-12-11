#include<stdio.h>
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)==2 && (m||n)){
        int a=m,b=n;
        if(n > m){
            int tmp=n;
            n=m;
            m=tmp;
        }
        int ans;
        if(n == 1) ans=m;
        else if(n == 2) ans= m / 4 * 4 + (m % 4 == 1? 2 : (m % 4 >= 2? 4 : 0));
        else ans=(n*m+1)/2;
        printf("%d knights may be placed on a %d row %d column board.\n",ans,a,b);
    }
    return 0;
}
