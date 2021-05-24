#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;
int main(){
    int N,tc=0;
    while(scanf("%d",&N)==1 && (!(N<0))){
        int ans;
        double lg;
        lg=log(N)/log(2);
        ans=(int) lg;
        if(lg-ans>eps)
            ans++;
        printf("Case %d: %d\n",++tc,ans);
    }
}
