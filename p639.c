#include<stdio.h>
#define Wall -1
#define Empty 0
#define Rook 1
#define max(a,b) (a)>(b)?(a):(b)
int N,Board[5][5],maxPossible,ans[20],mx;
int isValidComb(int Size){
  int i,u,d,r,l,row,col;
  for(i=0;i<Size;i++){
    row=ans[i]/N;
    col=ans[i]%N;
    for(u=row-1;u>=0;u--){
      if(Board[u][col]==Wall) break;
      if(Board[u][col]==Rook) return 0;
    }
    for(d=row+1;d<N;d++){
      if(Board[d][col]==Wall) break;
      if(Board[d][col]==Rook) return 0;
    }
    for(l=col-1;l>=0;l--){
      if(Board[row][l]==Wall) break;
      if(Board[row][l]==Rook) return 0;
    }
    for(r=col+1;r<N;r++){
      if(Board[row][r]==Wall) break;
      if(Board[row][r]==Rook) return 0;
    }
  }
  return 1;
}
void findMaxCom(int pos,int cnt){
  if(isValidComb(cnt)){
    mx=max(mx,cnt);
  }
  if(cnt>maxPossible || pos>=N*N) return;
  if(!Board[pos/N][pos%N]){
    Board[pos/N][pos%N]=Rook;
    ans[cnt]=pos;
    findMaxCom(pos+1,cnt+1);
    Board[pos/N][pos%N]=Empty;
  }
  findMaxCom(pos+1,cnt);
}
int main(){
  char line[10];
  int i,j;
  while(scanf("%d",&N)==1 && N){
    maxPossible=N*N;
    getchar();
    for(i=1;i<=N;i++){
      scanf("%s",line);
      for(j=0;j<N;j++){
        if(line[j]=='.')
          Board[i-1][j]=Empty;
        else{
          Board[i-1][j]=Wall;
          maxPossible--;
        }
      }
    }
    mx=-1;
    findMaxCom(0,0);
    printf("%d\n",mx);
  }
}
