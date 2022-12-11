#include<stdio.h>
int N,A[7],cnt;
void swap(int *a,int *b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
int sorted(){
  int i;
  for(i=0;i<N-1;i++){
    if(A[i]>A[i+1])
      return 0;
  }
  return 1;
}
void mapSwap(int swaped){
  int i,stts=0;
  if(!swaped){
    if(!sorted())
      return;
    cnt++;
  }
  if(!swaped && sorted())
    return;
  for(i=0;i<N-1;i++){
    if(A[i]>A[i+1]){
      stts=1;
      swap(A+i,A+i+1);
      mapSwap(1);
      swap(A+i,A+i+1);
    }
  }
  if(!stts)
    mapSwap(0);
}
int main(){
  int dSet=0;
  while(scanf("%d",&N)==1 && N){
    int i;
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
    cnt=0;
    if(!sorted())
      mapSwap(1);
    printf("There are %d swap maps for input data set %d.\n",cnt,++dSet);
  }
}
