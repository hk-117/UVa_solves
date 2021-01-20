#include<bits/stdc++.h>
using namespace std;
int main(){
  long long S[20],res,tmp;
  int N,i,j,cs=0;
  while(scanf("%d",&N)==1){
    cs++;
    for(i=0;i<N;i++){
      scanf("%lld",&S[i]);
    }
    res=0;
    for(i=0;i<N;i++){
      tmp=S[i];
      res=max(tmp,res);
      for(j=i+1;j<N;j++){
        tmp*=S[j];
        res=max(tmp,res);
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n",cs,res);
  }
}
