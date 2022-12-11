#include<stdio.h>
int main(){
  int t,N;
  scanf("%d",&t);
  while(t--){
    int i,mx=1,sum=0,prev,tmp;
    scanf("%d",&N);
    if(N==1){
      printf("1\n");
      continue;
    }
    scanf("%d",&prev);
    for(i=1;i<N;i++){
      scanf("%d",&tmp);
      if(sum+prev < tmp){
        mx++;
        sum+=prev;
      }
      prev=tmp;
    }
    printf("%d\n",mx);
  }
}
