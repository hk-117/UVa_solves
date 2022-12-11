#include<stdio.h>
#include<string.h>
int main(){
  int T,len,tc=0,i,j,comPos[100];
  char OutPut[100];
  double Total,Mean,inp;
  scanf("%d",&T);
  while(T--){
    int cnt=0;
    Total=0;
    for(i=0;i<12;i++){
      scanf("%lf",&inp);
      Total+=inp;
    }
    Mean=Total/12;
    sprintf(OutPut,"%.2lf",Mean);
    len=strlen(OutPut);
    memset(comPos,-1,sizeof comPos);
    for(i=len-4;i>=0;i--){
      cnt++;
      if(cnt%4==0){
        comPos[i+1]=1;
      }
    }
    printf("%d $",++tc);
    for(i=0;i<len;i++){
      if(comPos[i]==1){
        putchar(',');
      }
      putchar(OutPut[i]);
    }
    putchar('\n');
  }
}
