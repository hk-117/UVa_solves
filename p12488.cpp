#include<bits/stdc++.h>
using namespace std;
int S[25],E[25],PE[25];
int main(){
    int n;
    while(scanf("%d",&n)==1 && n){
        int i,j,mn=0;
        for(i=0;i<n;i++){
            scanf("%d",&S[i]);
        }
        for(i=0;i<n;i++){
            scanf("%d",&E[i]);
            PE[E[i]]=i;
        }
        for(i=n-1;i>=0;i--){
            for(j=i-1;j>=0;j--){
                if(PE[S[i]]-PE[S[j]] <0){
                    mn++;
                }
            }
        }
        printf("%d\n",mn);
    }
}
