#include<bits/stdc++.h>
#define scan(a,b) scanf("%lld %lld",&a,&b)
using namespace std;
int main(){
    long long  h,o;
    while(scan(h,o)==2){
        printf("%ld\n",labs(o-h));
    }
}
