#include<bits/stdc++.h>
#define scan(a,b) scanf("%lld %lld",&a,&b)
using namespace std;
int main(){
    long long a,b;
    int tc=0;
    while(scan(a,b)==2 && a||b){
        tc++;
        printf("Case %d: ",tc);
        if((a-1)/b>26)
            puts("impossible");
        else
            printf("%lld\n",(a-1)/b);
    }
}
