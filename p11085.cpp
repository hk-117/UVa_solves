#include<cstdio>
#include<cstdlib>
#include<climits>
using namespace std;
int row[8],soln[92][8],cnt;
int place(int r,int c){
  int prev;
  for(prev=0;prev<c;prev++)
    if(row[prev]==r || (abs(row[prev]-r)==abs(prev-c)))
      return 0;
  return 1;
}
void backtrack(int c){
  int r,j;
  if(c==8){
    for(j=0;j<8;j++)
      soln[cnt][j]=row[j]+1;
    cnt++;
  }
  for(r=0;r<8;r++){
    if(place(r,c)){
      row[c]=r;
      backtrack(c+1);
    }
  }
}
int main(){
  int Inp[8],i,j,cs=0;
  backtrack(0);
  while(scanf("%d",&Inp[0])==1){
    int stps=INT_MAX,tmpstps;
    cs++;
    for(i=1;i<8;i++)
      scanf("%d",&Inp[i]);
    for(i=0;i<cnt;i++){
      tmpstps=0;
      for(j=0;j<8;j++){
        if(soln[i][j]!=Inp[j])
          tmpstps++;
      }
      if(tmpstps<stps)
        stps=tmpstps;
    }
    printf("Case %d: %d\n",cs,stps);
  }
}
