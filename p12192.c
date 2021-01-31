#include<stdio.h>
#define MAX 501
int land[MAX][MAX],N,M,L,U,mx;
int lowerBound(int layer,int start,int end){
  int mid;
  if(land[layer][end]<L) return -1;
  if(land[layer][start]>=L) return start;
  while(start<=end){
    mid=start+(end-start)/2;
    if(land[layer][mid]>=L && land[layer][mid-1]<L)
      return mid;
    if(land[layer][mid]<L){
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
}
void DiagonalLB(int i,int j,int start,int end){
  int mid=start+(end-start)/2;
  if(start>end) return;
  if(land[i+mid-1][j+mid-1]>U){
    DiagonalLB(i,j,start,mid-1);
  }
  else{
    mx=mx>mid?mx:mid;
    DiagonalLB(i,j,mid+1,end);
  }
}
void findMaxLand(){
  int i,low,up,Property=0,j;
  for(i=0;i<N;i++){
    low=lowerBound(i,0,M-1);
    if(low==-1)
      continue;
    for(j=Property;j<N;j++){
      if(i+j>=N || low+j>=M || land[i+j][low+j]>U)
        break;
      if(j+1>Property)
        Property=j+1;
    }
  }
  mx=Property;
}
int main(){
  int Q;
  while(scanf("%d %d",&N,&M)==2 && (N||M)){
    int i,j;
    for(i=0;i<N;i++){
      for(j=0;j<M;j++){
        scanf("%d",&land[i][j]);
      }
    }
    scanf("%d",&Q);
    while(Q--){
      scanf("%d %d",&L,&U);
      mx=0;
      findMaxLand();
      printf("%d\n",mx);
    }
    printf("-\n");
  }
}
