#include<stdio.h>
#define M 100
int main(){
  char F[M];
  int i,T,tc=0,N;
  scanf("%d",&T);
  while(T--){
    int sc=0;
    scanf("%d %s",&N,F);
    i=0;
    while(i<N){
      if(F[i]=='#') i++;
      else{
        sc++;
        i+=3;
      }
    }
    printf("Case %d: %d\n",++tc,sc);
  }
}
