#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  return (b==0? a:(gcd(b,a%b)));
}
int main(){
  int step,md;
  while(cin>>step>>md){
    if(gcd(step,md)==1){
      printf("%10d %9d    %s\n",step,md,"Good Choice");
    }
    else{
      printf("%10d %9d    %s\n",step,md,"Bad Choice");
    }
    puts("");
  }
}
