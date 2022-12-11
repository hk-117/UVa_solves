#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct{
  int rt,wt;
} Soldier;
Soldier S[1005];
int cmp(const void *a,const void *b){
  Soldier* at= (Soldier*) a;
  Soldier* bt= (Soldier*) b;
  if(at->wt == bt->wt)
    return bt->rt - at->rt;
  else
    return bt->wt - at->wt;
}
int main(){
  int N,tc=0;
  while(scanf("%d",&N)==1 && N){
    int i,j,timeStamp=0,maxTime=0,report=0;
    for(i=0;i<N;i++){
      scanf("%d %d",&S[i].rt,&S[i].wt);
    }
    qsort(S,N,sizeof S[0],cmp);
    for(i=0;i<N;i++){
      report+= S[i].rt;
      timeStamp= report+S[i].wt;
      maxTime=max(maxTime,timeStamp);
    }
    printf("Case %d: %d\n",++tc,maxTime);
  }
}
