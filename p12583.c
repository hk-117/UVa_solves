#include<stdio.h>
#include<string.h>
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,k,i,j,cnt=0;
        char Nms[505];
        scanf("%d %d %s",&n,&k,Nms);
        for(i=0;i<n;i++){
            for(j=i-k<0?0:i-k;j>=0 && j<i;j++){
                if(Nms[j]==Nms[i]){
                    cnt++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",++tc,cnt);
    }
}
