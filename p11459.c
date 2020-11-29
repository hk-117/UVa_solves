#include<stdio.h>
#define DEST 100
int P[1000005],Throw,Players,SoL,Gover;
int main(){
  int i,pos1,pos2,T,Turn,Board[101],TRes;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d",&Players,&SoL,&Throw);
    Turn=1;
    Gover=0;
    for(i=1;i<=Players;i++) P[i]=1;
    for(i=0;i<101;i++) Board[i]=0;
    for(i=1;i<=SoL;i++){
      scanf("%d %d",&pos1,&pos2);
      Board[pos1]=pos2;
    }
    for(i=1;i<=Throw;i++){
      scanf("%d",&TRes);
      if(!Gover){
        P[Turn]+=TRes;
        if(Board[P[Turn]]!=0)
          P[Turn]=Board[P[Turn]];
        if(P[Turn]>=DEST){ 
          Gover=1;
          P[Turn]=DEST;
        }
        Turn++;
        if(Turn>Players) Turn=1;
      }
    }
    for(i=1;i<=Players;i++)
      printf("Position of player %d is %d.\n",i,P[i]);
  }
}
