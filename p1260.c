#include<stdio.h>
#include<stdlib.h>
int S[1020];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        int ans=0,i,j;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&S[i]);
        }
        for(i=1;i<n;i++){
            for(j=i-1;j>=0;j--){
                if(S[j]>S[i]){
                    continue;
                }
                else{
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}
