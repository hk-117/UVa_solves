#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a[3];
  while(scanf("%lld %lld %lld",&a[0],&a[1],&a[2])==3 && (a[0]||a[1]||a[2])){
    sort(a,a+3);
    if(a[2]*a[2]== (a[0]*a[0]+a[1]*a[1])){
      puts("right");
    }
    else
      puts("wrong");
  }
}
