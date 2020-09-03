#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int W[25],dp[105];
char line[250];
int main(){
    int t,i,j,tot,mid,N;
    scanf("%d",&t);
    getchar();
    while(t--){
        char *p;
        fgets(line,sizeof line,stdin);
        line[strcspn(line,"\n")]='\0';
        p =strtok(line," ");
        i=0;
        tot=0;
        while(p!=0){
            W[i]= atoi(p);
            tot+=W[i];
            ++i;
            p=strtok(NULL," ");
        }
        N=i;
        mid=tot/2;
        if(tot%2){
            puts("NO");
            continue;
        }
        memset(dp,-1,sizeof dp);
        dp[0]=0;
        for(i=0;i<N;i++){
            for(j=mid;j>=0;j--){
                if(dp[j]>=0){
                    dp[j+W[i]]=1;
                }
            }
        }
        if(dp[mid]==1)
            puts("YES");
        else
            puts("NO");
    }
}
