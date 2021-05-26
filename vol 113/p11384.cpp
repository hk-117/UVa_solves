#include<cstdio>
#include<cmath>
#define eps 1e-9
using namespace std;
int main(){
    long long N;
    int L;
    while(scanf("%lld",&N)==1){
        L= ceil(eps+ (log(N)/log(2)));
        printf("%d\n",L);
    }
}
