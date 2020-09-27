#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int trm;
ll L;
void calcTrm(ll A){
  if(A>L) return;
  if(A==1){trm++;return;}
  if(A%2==0) {trm++; calcTrm(A/2);}
  else {trm++; calcTrm(3*A+1);}
}
int main(){
  ll A,tc=0;
  while(scanf("%lld %lld",&A,&L)==2 && !(A<0) && !(L<0)){
    trm=0;
    printf("Case %lld: A = %lld, limit = %lld, ",++tc,A,L);
    calcTrm(A);
    printf("number of terms = %d\n",trm);
  }
}
