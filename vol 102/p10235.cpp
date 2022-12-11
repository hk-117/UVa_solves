#include<bits/stdc++.h>
using namespace std;
bitset<1000010> bs;
void createPrime(){
  int sieve_size=1000010;
  bs.set();
  bs[0]=bs[1]=0;
  for(long long i=2;i<=sieve_size;i++)
    if(bs[i])
      for(long long j=i*i;j<=sieve_size;j+=i) bs[j]=0;
}
int main(){
  string inp,rev;
  createPrime();
  while(cin>>inp){
    rev=inp;
    reverse(rev.begin(),rev.end());
    int N= atoi(inp.c_str());
    int RN=atoi(rev.c_str());
    printf("%d is ",N);
    if(!bs[N]) 
      printf("not prime.\n");
    else if(N!=RN && bs[RN]) 
      printf("emirp.\n");
    else 
      printf("prime.\n");
  }
}
