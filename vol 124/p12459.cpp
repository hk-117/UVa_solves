#include<cstdio>
using namespace std;
long long Tbl[81];
long long findGen(int G){
  if(G<=0) return Tbl[0];
  if(G==1) return Tbl[1];
  if(G==2) return Tbl[2];
  if(Tbl[G]) return Tbl[G];
  return Tbl[G]=findGen(G-1)+findGen(G-2);
}
int main(){
  int G;
  Tbl[1]=1;
  Tbl[2]=2;
  while(scanf("%d",&G)==1 && G){
    printf("%lld\n",findGen(G));
  }
}
