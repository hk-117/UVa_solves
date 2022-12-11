#include<stdio.h>
int W[50];
int main(){
  int T,n,P,Q,tc=0;
  scanf("%d",&T);
  while(T--){
    int i,tot=0;
    tc++;
    scanf("%d %d %d",&n,&P,&Q);
    for(i=0;i<n;i++){
      scanf("%d",&W[i]);
      if(P>0 && W[i]<=Q){
        tot++;
        P--;
        Q-=W[i];
      }
    }
    printf("Case %d: %d\n",tc,tot);
  }
}
