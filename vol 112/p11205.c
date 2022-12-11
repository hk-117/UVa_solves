#include<stdio.h>
#define min(a,b) (a)<(b)?(a):(b)
int P,N,mn,Map[105],States[105],comb;
void findMinBits(int pos,int cnt){
  int litBits;
  if(cnt>P || pos>P) return;
  if(cnt>=0){
    int i,j,flag=1;
    for(i=0;i<N && flag;i++){
      litBits= States[i] & comb;
      for(j=0;j<i;j++){
        if(Map[j]==litBits)
          flag=0;
      }
      Map[i]=litBits;
    }
    if(flag)
      mn=min(mn,cnt);
  }
  comb|=(1<<pos);
  findMinBits(pos+1,cnt+1);
  comb ^=(1<<pos);
  findMinBits(pos+1,cnt);
}
int main(){
  int i,j,t;
  scanf("%d",&t);
  while(t--){
    int binToDec,bit;
    scanf("%d %d",&P,&N);
    for(i=0;i<N;i++){
      binToDec=0;
      for(j=0;j<P;j++){
        scanf("%d",&bit);
        if(bit){
          binToDec|=(1<<(P-j-1));
        }
      }
      States[i]=binToDec;
    }
    comb=0;
    mn=20;
    findMinBits(0,0);
    printf("%d\n",mn);
  }
}
