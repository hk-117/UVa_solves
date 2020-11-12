#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,a,b,c;
  scanf("%d",&N);
  while(N--){
    scanf("%d %d %d",&a,&b,&c);
    if(a<=0 || b<=0 || c<=0){
      puts("Wrong!!");
    }
    else if(a+b<=c || b+c<=a || c+a<=b){
      puts("Wrong!!");
    }
    else
      puts("OK");
  }
}
