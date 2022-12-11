#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  long long fct=1;
  while(scanf("%d",&N)==1){
    if(N<0){
      if((abs(N))%2){
        puts("Overflow!");
      }
      else{
        puts("Underflow!");
      }
    }
    else if(N>13){
      puts("Overflow!");
    }
    else if(N<8){
      puts("Underflow!");
    }
    else{
      fct=1;
      while(N!=0){
        fct *= N;
        N--;
      }
      printf("%lld\n",fct);
    }
  }
}
