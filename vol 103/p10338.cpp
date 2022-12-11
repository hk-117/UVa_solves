#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,tc=0;
  long long F[21];
  F[0]=1;
  for(int i=1;i<=20;i++){
    F[i]=F[i-1]*i;
  }
  cin>>N;
  string wrd;
  while(N--){
    int W[100]={0};
    cin>>wrd;
    for(int i=0;i<wrd.size();i++){
      W[wrd[i]]++;
    }
    long long D=1;
    for(int i='A';i<='Z';i++){
      if(W[i]>0){
        D*=F[W[i]];
      }
    }
    cout<<"Data set "<< ++tc <<": "<< F[wrd.size()] / D <<endl;
  }
}
