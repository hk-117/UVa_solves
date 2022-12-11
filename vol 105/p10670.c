#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
  char Name[20];
  int Cost;
} Agency;
Agency agencies[105];
int M,N,L;
int cmp(const void *a,const void *b){
  Agency *at= (Agency*) a;
  Agency *bt= (Agency*) b;
  if(at->Cost == bt->Cost)
    return strcmp(at->Name,bt->Name);
  else
    return (at->Cost - bt->Cost);
}
int findCost(int A,int B){
  int Cost=0,n=N,m=M,half;
  if(A==0) return A;
  half=n/2;
  while((n-(n-half))>=m && half){
    if((n-half) * A > B){
      Cost+= B;
    }
    else{
      Cost+=(n-half)*A;
    }
    n-= (n-half);
    half=n/2;
  }
  if(n>m)
    Cost+=(n-m)*A;
  return Cost;
}
int main(){
  int t,tc=0;
  char Nm[20];
  scanf("%d",&t);
  while(t--){
    int i,A,B;
    scanf("%d %d %d",&N,&M,&L);
    getchar();
    for(i=0;i<L;i++){
      scanf("%[^:]",Nm);
      getchar();
      scanf("%d,%d",&A,&B);
      getchar();
      strcpy(agencies[i].Name,Nm);
      agencies[i].Cost=findCost(A,B);
    }
    qsort(agencies,L,sizeof agencies[0],cmp);
    printf("Case %d\n",++tc);
    for(i=0;i<L;i++){
      printf("%s %d\n",agencies[i].Name,agencies[i].Cost);
    }
  }
}
