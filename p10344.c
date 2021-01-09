#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int status;
char sym[]="+-*";
void IntSwap(int *a,int *b){
  int tmp=*a;
  *a=*b;
  *b=tmp;
}
int evalExpr(char *symSeq,int *Vals){
  int s=Vals[0],i;
  for(i=1;i<5;i++){
    if(symSeq[i-1]=='+'){
      s+=Vals[i];
    }
    else if(symSeq[i-1]=='-'){
      s-=Vals[i];
    }
    else{
      s*=Vals[i];
    }
  }
  if(s==23)
    return 1;
  return 0;
}
void IntPermute(int *arr,int l,int r){
  int i;
  if(status)
    return;
  if(l==r){
    char tmp[4];
    int j,k,l,m;
    for(j=0;j<3;j++){
      for(k=0;k<3;k++){
        for(l=0;l<3;l++){
          for(m=0;m<3;m++){
            tmp[0]=sym[j];
            tmp[1]=sym[k];
            tmp[2]=sym[l];
            tmp[3]=sym[m];
            status=evalExpr(tmp,arr);
            if(status)
              return;
          }
        }
      }
    }
  }
  else{
    for(i=l;i<=r;i++){
      IntSwap(arr+l,arr+i);
      IntPermute(arr,l+1,r);
      IntSwap(arr+l,arr+i);
    }
  }
}
int main(){
  int i,V[5];
  while(1){
    scanf("%d%d%d%d%d",&V[0],&V[1],&V[2],&V[3],&V[4]);
    if(!(V[0]||V[1]||V[2]||V[3]||V[4])){
      break;
    }
    status=0;
    IntPermute(V,0,4);
    if(status)
      puts("Possible");
    else
      puts("Impossible");
  }
}
