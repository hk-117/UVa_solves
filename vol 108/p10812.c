#include<stdio.h>
int main(){
  int T;
  long long int s,d,a,b;
  scanf("%d",&T);
  while(T--){
    scanf("%lld %lld",&s,&d);
    if(d>s){
      puts("impossible");
    }
    else{
      a=(s+d)/2;
      b=s-a;
      if(b<0||(s+d)%2==1){
        puts("impossible");
      }
      else{
        if(a>b)
          printf("%lld %lld\n",a,b);
        else
          printf("%lld %lld\n",b,a);
      }
    }
  }
}
