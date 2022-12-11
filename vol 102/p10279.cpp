#include<cstdio>
using namespace std;
char Mines[11][11],Moves[11][11];
int Ns[11][11];
int xs[]={-1,-1,-1,0,0,1,1,1};
int ys[]={-1,0,1,-1,1,-1,0,1};
int isValidPos(int x,int y,int N){
  if((x>=0 && x<N) && (y>=0 && y<N))
    return 1;
  return 0;
}
int countAdj(int posx,int posy,int N){
  int curx=posx,cury=posy,m=0;
  for(int i=0;i<8;i++){
    curx=posx+xs[i];
    cury=posy+ys[i];
    if(isValidPos(curx,cury,N)){
      if(Mines[curx][cury]=='*')
        m++;
    }
  }
  return m;
}
int main(){
  int Finished,G,N,i,j,nl=0;
  scanf("%d",&G);
  while(G--){
    if(nl) putchar('\n');
    else nl=1;
    scanf("%d",&N);
    getchar();
    Finished=0;
    for(i=0;i<N;i++){
      scanf("%s",Mines[i]);
    }
    for(i=0;i<N;i++){
      scanf("%s",Moves[i]);
    }
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        if(Moves[i][j]=='x'){
          if(Mines[i][j]=='*'){
            Finished=1;
          }
          else{
            Ns[i][j]=countAdj(i,j,N);
          }
        }
      }
    }
    if(Finished){
      for(i=0;i<N;i++){
        for(j=0;j<N;j++){
          if(Moves[i][j]=='x' && Mines[i][j]=='*'){
            putchar('*');
          }
          else if(Moves[i][j]=='x' && Mines[i][j]=='.'){
            printf("%d",Ns[i][j]);
          }
          else if(Moves[i][j]=='.' && Mines[i][j]=='*'){
            putchar('*');
          }
          else{
            putchar('.');
          }
        }
        putchar('\n');
      }
    }
    else{
      for(i=0;i<N;i++){
        for(j=0;j<N;j++){
          if(Moves[i][j]=='x' && Mines[i][j]=='.'){
            printf("%d",Ns[i][j]);
          }
          else{
            putchar('.');
          }
        }
        putchar('\n');
      }
    }
  }
}
