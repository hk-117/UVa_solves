#include<cstdio>
#include<cstring>
using namespace std;
int mask[10100],P[10000];
void createPrime(){
  int i,j,sieve_size=10100;
  memset(mask,0,sizeof mask);
  mask[0]=mask[1]=1;
  P[0]=1;
  for(i=2;i<=sieve_size;i++){
    if(!mask[i]){
      for(j=i*i;j<=sieve_size;j+=i) mask[j]=1;
      P[P[0]++]=i;
    }
  }
}
int main(){
  int n;
  createPrime();
  while(scanf("%d",&n)==1 && n){
    int i,j,sum=0,cnt=0;
    for(i=1;P[i]<=n && i<P[0];i++){
      sum=0;
      for(j=i;P[j]<=n && j<P[0];j++){
        sum+=P[j];
        if(sum==n){
          cnt++;
          break;
        }
        if(sum>n) break;
      }
    }
    printf("%d\n",cnt);
  }
}
