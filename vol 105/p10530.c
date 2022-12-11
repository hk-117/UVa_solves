#include<stdio.h>
#include<string.h>
#define H 1
#define L 0
int main(){
  int Gs,honest=1,i,Gtable[11];
  char tmp[5],st[10];
  memset(Gtable,-1,sizeof Gtable);
  while(scanf("%d",&Gs)==1 && Gs){
    getchar();
    scanf("%s %s",tmp,st);
    if(strcmp(st,"high")==0){
      if(Gtable[Gs]==-1)
        Gtable[Gs]=H;
      else{
        if(Gtable[Gs]!=1)
          honest=0;
      }
    }
    else if(strcmp(st,"low")==0){
      if(Gtable[Gs]==-1)
        Gtable[Gs]=L;
      else{
        if(Gtable[Gs]!=0)
          honest=0;
      }
    }
    else{
      for(i=1;i<11 && honest;i++){
        if(Gtable[i]!=-1){
          if((i<Gs && Gtable[i]==H)||(i>Gs && Gtable[i]==L)){
            honest=0;
          }
          else{
            if(i==Gs) 
              honest=0;
          }
        }
      }
      if(honest) 
        puts("Stan may be honest");
      else 
        puts("Stan is dishonest");
      memset(Gtable,-1,sizeof Gtable);
      honest=1;
    }
  }
}
