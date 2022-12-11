#include<stdio.h>
typedef struct{
  int Set,Value;
} Common;
int N,M,tmp,ans,mx,rels,RealCap[25];
Common Cmn[100];
int calCust(){
  int i,j,res=0,common;
  for(i=0;i<N;i++){
    if(tmp & (1<<i)){
      res+= RealCap[i];
    }
  }
  for(i=0;i<rels;i++){
    int isect=0;
    common= Cmn[i].Set & tmp;
    while(common){
      isect++;
      common &= (common-1);
    }
    if(isect>1){
      res-= (isect-1) * Cmn[i].Value;
    }
  }
  return res;
}
void findMaxCus(int pos,int cnt){
  if(cnt==M){
    int res;
    res=calCust();
    if(res>mx){
      mx=res;
      ans=tmp;
    }
  }
  if(pos>=N || cnt>=M) return;
  tmp|=(1<<pos);
  findMaxCus(pos+1,cnt+1);
  tmp &= (~(1<<pos));
  findMaxCus(pos+1,cnt);
}
int main(){
  int i,j,k,tc=0;
  while(scanf("%d %d",&N,&M)==2 && (N||M)){
    int tcomn,tcomsize,pos;
    for(i=0;i<N;i++){
      scanf("%d",&RealCap[i]);
    }
    scanf("%d",&rels);
    for(i=0;i<rels;i++){
      scanf("%d",&tcomsize);
      tcomn=0;
      for(j=0;j<tcomsize;j++){
        scanf("%d",&pos);
        tcomn|= (1<< (pos-1));
      }
      scanf("%d",&Cmn[i].Value);
      Cmn[i].Set= tcomn;
    }
    mx=-1;
    tmp=0;
    ans=0;
    findMaxCus(0,0);
    printf("Case Number  %d\n",++tc);
    printf("Number of Customers: %d\n",mx);
    printf("Locations recommended:");
    for(i=0;i<N;i++){
      if(ans & (1<<i))
      printf(" %d",i+1);
    }
    printf("\n\n");
  }
}
