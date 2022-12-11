#include<bits/stdc++.h>
#define scan(a) scanf("%lld",&a)
using namespace std;
int main(){
    long long tc;
    scan(tc);
    while(tc--){
        long long in;
        scan(in);
        long long root;
        root= (-1+sqrt(1+4*2*in))/2;
        printf("%lld\n",root);
    }
}
