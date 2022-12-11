#include<stdio.h>
#define min(a,b) (a)<(b)?(a):(b)
int ladder[100005],n;
int sPossible(int k){
  int i,j,prev=0;
  for(i=0;i<n;i++){
    if(ladder[i]-prev == k){
      --k;
    }
    else if(ladder[i]-prev > k){
      return 0;
    }
    else{
      k=k;
    }
    prev=ladder[i];
  }
  return 1;
}
int main(){
  int t,tc=0;
  scanf("%d",&t);
  while(t--){
    int i,l,r,m,ans=100000000;
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&ladder[i]);
    }
    l=1;
    r=ladder[n-1];
    while(l<=r){
      m=(l+r)/2;
      if(!sPossible(m)){
        l=m+1;
      }
      else{
        ans=min(ans,m);
        r=m-1;
      }
    }
    printf("Case %d: %d\n",++tc,ans);
  }
}
