#include<stdio.h>
int main(){
  int i,N;
  while(scanf("%d",&N)==1 && N){
    int sum=0,tmp,sp=0;
    for(i=0;i<N;i++){
      scanf("%d",&tmp);
      sum+=tmp;
      if(tmp>0){
        if(sp){
          printf(" %d",tmp);
        }
        else{
          printf("%d",tmp);
          sp=1;
        }
      }
    }
    if(!sum)
      printf("%d\n",sum);
    else
      printf("\n");
  }
}
