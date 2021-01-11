#include<stdio.h>
#include<string.h>
typedef struct{
  int s,f;
} Tile;
int N,M,flag,taken[20];
Tile T[20],tArr[20];
void swap(int *a,int *b){
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
int isValid(Tile tmp,int i){
  if(tArr[i-1].f==tmp.s){
    tArr[i]=tmp;
    return 1;
  }
  else if(tArr[i-1].f==tmp.f && i!=N+1){
    swap(&tmp.s,&tmp.f);
    tArr[i]=tmp;
    return 1;
  }
  else
    return 0;
}
void findAnswer(int sz){
  int j;
  if(flag)
    return;
  if(sz==N+1 && isValid(tArr[N+1],sz)){
    flag=1;
    return;
  }
  if(sz>N)
    return;
  for(j=1;j<=M;j++){
    if(!taken[j] && isValid(T[j],sz)){
      taken[j]=1;
      findAnswer(sz+1);
      taken[j]=0;
    }
  }
}
int main(){
  int i;
  while(scanf("%d",&N)==1 && N){
    scanf("%d",&M);
    scanf("%d%d%d%d",&tArr[0].s,&tArr[0].f,&tArr[N+1].s,&tArr[N+1].f);
    for(i=1;i<=M;i++){
      scanf("%d %d",&T[i].s,&T[i].f);
    }
    flag=0;
    memset(taken,0,sizeof taken);
    findAnswer(1);
    if(flag)
      puts("YES");
    else
      puts("NO");
  }
}
