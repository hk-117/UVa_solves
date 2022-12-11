#include<stdio.h>
int N,P[25],Pi[25],avg;
void findPidx(){
  int i,j,total;
  for(i=0;i<(1<<N);i++){
    total=0;
    for(j=0;j<N;j++){
      if(i & (1<<j)){
        total+=P[j];
      }
    }
    if(total>=avg){
      for(j=0;j<N;j++){
        if((i&(1<<j)) && total-P[j]<avg)
          Pi[j]++;
      }
    }
  }
}
int main(){
  int T,i;
  scanf("%d",&T);
  while(T--){
    avg=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%d",&P[i]);
      avg+=P[i];
      Pi[i]=0;
    }
    avg=avg/2 +1;
    findPidx();
    for(i=0;i<N;i++){
      printf("party %d has power index %d\n",i+1,Pi[i]);
    }
    printf("\n");
  }
}
