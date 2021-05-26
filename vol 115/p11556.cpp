#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    long long N,pwr;
    int b;
    while(scanf("%lld %d",&N,&b)==2){
        pwr= pow(2,b+1);
        if(N<pwr)
            puts("yes");
        else
            puts("no");
    }
}
