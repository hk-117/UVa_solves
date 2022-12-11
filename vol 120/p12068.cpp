#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
  return (b==0? a:(gcd(b,a%b)));
}
long long lcm(long long a,long long b){
  return a*(b/gcd(a,b));
}
long long findLCM(vector<int> &A){
  long long l=1;
  for(int i=0;i<A.size();i++){
    l=lcm(l,A[i]);
  }
  return l;
}
int main(){
  int S,tc=0;
  cin>>S;
  while(S--){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
      cin>>A[i];
    }
    long long l=findLCM(A),DEN=0,NUM,G;
    for(int i=0;i<N;i++){
      DEN+= l/A[i];
    }
    NUM=l*N;
    G=gcd(NUM,DEN);
    printf("Case %d: %lld/%lld\n",++tc,NUM/G,DEN/G);
  }
}
