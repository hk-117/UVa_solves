#include<bits/stdc++.h>
#define MX 1000001
using namespace std;
bitset<MX> S;
void chkGen(long long N){
  string s=to_string(N);
  for(int i=0;i<s.size();i++){
    N+= s[i]-'0';
  }
  if(N>MX-1) return;
  else{
    if(S[N])
      chkGen(N);
    S[N]=0;
  }
}
int main(){
  S.set();
  for(int i=1;i<MX;i++){
    if(S[i]){
      chkGen(i);
      printf("%d\n",i);
    }
  }
}
