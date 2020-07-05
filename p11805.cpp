#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        tc++;
        printf("Case %d: ",tc);
        int n,k,p;
        scanf("%d %d %d",&n,&k,&p);
        if(((k+p)%n)>0){
            printf("%d\n", (k+p)%n);
        }
        else{
            printf("%d\n",n);
        }
    }
}
