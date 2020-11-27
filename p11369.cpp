#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,n;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    vector<int> P(n);
    for(int i=0;i<n;i++){
      scanf("%d",&P[i]);
    }
    sort(P.begin(),P.end(),greater<int>());
    int mx=0;
    for(int i=2;i<P.size();i+=3){
      mx+=P[i];
    }
    printf("%d\n",mx);
  }
}
