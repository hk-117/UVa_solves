#include<cstdio>
using namespace std;
int main(){
  long long N,tot,n,sum,U;
  while(scanf("%lld",&N)==1){
    n= (N-1)/2 +1;
    tot= n*n;
    U= 2*tot +1;
    sum= (U-2)+ (U-4)+ (U-6);
    printf("%lld\n",sum);
  }
}
