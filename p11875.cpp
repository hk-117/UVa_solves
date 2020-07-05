#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        tc++;
        printf("Case %d: ",tc);
        int n,res,mid,inp;
        scanf("%d",&n);
        mid= (n/2)+1;
        for(int i=1;i<=n;i++){
            scanf("%d",&inp);
            if(i==mid)
                res=inp;
        }
        printf("%d\n",res);
    }
}
