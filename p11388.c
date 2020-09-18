#include<stdio.h>
long long gcd(long long a,long long b){
  return (b==0?a: (gcd(b,a%b)));
}
long long lcm(long long a,long long b){
  return a*(b/gcd(a,b));
}
int main(){
  int t;
  long long a,b;
  scanf("%d",&t);
  while(t--){
    long long g,l;
    scanf("%lld %lld",&a,&b);
    g= gcd(a,b);
    l= lcm(a,b);
    if(g==a && l==b){
      printf("%lld %lld\n",a,b);
    }
    else{
      puts("-1");
    }
  }
}
