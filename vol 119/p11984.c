#include<stdio.h>
int main(){
  double I,C,F;
  int T,tc=0;
  scanf("%d",&T);
  while(T--){
    scanf("%lf %lf",&I,&F);
    C=I+(5.0/9.0)*F;
    printf("Case %d: %.2lf\n",++tc,C);
  }
}
