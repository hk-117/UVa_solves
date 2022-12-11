#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int AbsVal[100],Balls[100];
int main(){
  int N,B,i,j,dif;
  while(scanf("%d %d",&N,&B)==2 && (N||B)){
    for(i=0;i<B;i++){
      scanf("%d",&Balls[i]);
    }
    memset(AbsVal,0,sizeof AbsVal);
    for(i=0;i<B;i++){
      for(j=i;j<B;j++){
        dif= abs(Balls[i]-Balls[j]);
        AbsVal[dif]=1;
      }
    }
    dif=1;
    for(i=0;i<=N;i++){
      if(AbsVal[i]!=1){
        dif=0;
      }
    }
    if(dif){
      puts("Y");
    }
    else{
      puts("N");
    }
  }
}
