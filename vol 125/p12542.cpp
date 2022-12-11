#include<bits/stdc++.h>
using namespace std;
bitset<100010>mask;
void createPrime(){
  long long i,j,sieve_size=100010;
  mask.set();
  mask[0]=mask[1]=0;
  for(i=2;i<=sieve_size;i++){
    if(mask[i])
      for(j=i*i;j<=sieve_size;j+=i) mask[j]=0;
  }
}
int main(){
  string num;
  createPrime();
  while(cin>>num,num!="0"){
    int mx=INT_MIN;
    for(int i=0;i<num.size();i++){
      string tmp;
      for(int j=i;j<num.size() && j<(i+5);j++){
        tmp+=num[j];
        int n=atoi(tmp.c_str());
        if(mask[n]){
          mx=max(mx,n);
        }
      }
    }
    printf("%d\n",mx);
  }
}
