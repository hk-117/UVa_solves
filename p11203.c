#include<stdio.h>
#include<string.h>
typedef struct{
  int pM,pE,A,wt;
}Rs;
char St[60];
int sz;
Rs evalRule(){
  int i,cntm=0,cnte=0;
  Rs tmp;
  tmp.pM=-1;
  tmp.pE=-1;
  tmp.wt=0;
  tmp.A=1;
  sz=strcspn(St,"\n");
  for(i=0;i<sz;i++){
    if(!(St[i]=='M'||St[i]=='E'||St[i]=='?')){
      tmp.A=0;
      break;
    }
    else{
      if(St[i]=='M'){
        cntm++;
        if(cntm>1){
          tmp.A=0;
          break;
        }
        tmp.pM=i;
      }
      else if(St[i]=='E'){
        cnte++;
        if(cnte>1){
          tmp.A=0;
          break;
        }
        tmp.pE=i;
      }
      else{
        tmp.wt++;
      }
    }
  }
  return tmp;
}
int isValid(Rs tmp){
  int wtb,wta,wtm,bias;
  wtb=tmp.pM;
  wta=sz-(tmp.pE+1);
  wtm=tmp.wt-(wtb+wta);
  if(wtb==0 || wtm<=0 || wta==0)
    return 0;
  bias=1-wtm;
  wtm+=bias;
  wta+=bias;
  if(wtb==wta-1 && wtm==1)
    return 1;
  return 0;
}
int main(){
  int T;
  Rs r;
  scanf("%d",&T);
  getchar();
  while(T--){
    fgets(St,sizeof St,stdin);
    r=evalRule();
    if(r.A==0|| (!isValid(r))){
      puts("no-theorem");
    }
    else{
      puts("theorem");
    }
  }
}
