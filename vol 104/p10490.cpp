#include<bits/stdc++.h>
using namespace std;
bool isPrime(long long N){
  int i,sq= sqrt(N)+1;
  if(N==2) return true;
  if(N%2==0) return false;
  for(i=3;i<=sq;i+=2){
    if(N%i==0) return false;
  }
  return true;
}
int main(){
  int N;
  while(scanf("%d",&N)==1 && N){
    long long R= pow(2,N) -1 ;
    if(isPrime(N)){
      if(isPrime(R)){
        printf("Perfect: %lld!\n",(long long)(R*pow(2,N-1)));
      }
      else{
        puts("Given number is prime. But, NO perfect number is available.");
      }
    }
    else{
      puts("Given number is NOT prime! NO perfect number is available.");
    }
  }
}
