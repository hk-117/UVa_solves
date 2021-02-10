#include<cstdio>
#include<cstring>
#define MD 1000000
using namespace std;
int Table[105][105];
int ways(int n,int k){
  if(k==1){
    return 1;
  }
  if(Table[n][k]!=-1) return Table[n][k];
  int ans=0;
  for(int i=0;i<=n;i++){
    ans= (ans+ ways(n-i,k-1)) % MD;
  }
  return (Table[n][k]=ans);
}
int main(){
  int N,K;
  memset(Table,-1,sizeof Table);
  while(scanf("%d %d",&N,&K)==2 && (N||K)){
    printf("%d\n",ways(N,K));
  }
}
