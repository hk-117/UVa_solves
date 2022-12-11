#include<bits/stdc++.h>
using namespace std;
int N,nX[]={-1,0,1,-1,1,-1,0,1},nY[]={-1,-1,-1,0,0,1,1,1},taken[25][25];
char Table[25][25],w[410];
struct cmp{
  bool operator() (string a,string b) const{
    if(a.size()==b.size())
      return a<b;
    return a.size()<b.size();
  }
};
set<string,cmp> Dictionary;
int isValidPos(int x,int y){
  if(x<0 || y<0 || x>=N || y>=N)
    return 0;
  return 1;
}
void geneRator(int i,int j,int len){
  int pos,x,y;
  if(len>=3 && len<= N*N){
    w[len]='\0';
    Dictionary.insert(string(w));
  }
  if(len>=N*N)
    return;
  for(pos=0;pos<8;pos++){
    x=nX[pos]+i;
    y=nY[pos]+j;
    if(isValidPos(x,y) && Table[i][j]<Table[x][y] && (!taken[x][y])){
      w[len]=Table[x][y];
      taken[x][y]=1;
      geneRator(x,y,len+1);
      taken[x][y]=0;
    }
  }
}
int main(){
  int T;
  scanf("%d",&T);
  getchar();
  while(T--){
    int i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++){
      scanf("%s",Table[i]);
    }
    for(i=0;i<25;i++)
      for(j=0;j<25;j++)
        taken[i][j]=0;
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        w[0]=Table[i][j];
        taken[i][j]=1;
        geneRator(i,j,1);
        taken[i][j]=0;
      }
    }
    for(auto it=Dictionary.begin();it!=Dictionary.end();it++)
      cout<< *it <<"\n";
    Dictionary.clear();
    if(T)
      puts("");
  }
}
