#include<bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  while(scanf("%lld",&N)==1 && !(N<0)){
    long long ans;
    if(N==1) printf("0%%\n");
    else if(N==2) printf("50%%\n");
    else if(N==3) printf("75%%\n");
    else{
      printf("%lld%%\n",N*25);
    }
  }
}
