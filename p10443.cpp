#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
vector<string> Board;
int r,c,n,movx[]={-1,0,0,1},movy[]={0,-1,1,0};
bool isValid(int i,int j){
  if(i<0||i>=r||j<0||j>=c)
    return false;
  return true;
}
void printBoard(){
  R(i,0,r,1){
    R(j,0,c,1){
      putchar(Board[i][j]);
    }
    putchar('\n');
  }
}
void Attack(){
  int nxtx,nxty;
  vector<string>tmp;
  tmp=Board;
  R(i,0,r,1){
    R(j,0,c,1){
      if(Board[i][j]=='R'){
        R(k,0,8,1){
          nxtx=i+movx[k];
          nxty=j+movy[k];
          if(isValid(nxtx,nxty)){
            if(Board[nxtx][nxty]=='S'){
              tmp[nxtx][nxty]='R';
            }
          }
        }
      }
      else if(Board[i][j]=='S'){
        R(k,0,8,1){
          nxtx=i+movx[k];
          nxty=j+movy[k];
          if(isValid(nxtx,nxty)){
            if(Board[nxtx][nxty]=='P'){
              tmp[nxtx][nxty]='S';
            }
          }
        }
      }
      else{
        R(k,0,8,1){
          nxtx=i+movx[k];
          nxty=j+movy[k];
          if(isValid(nxtx,nxty)){
            if(Board[nxtx][nxty]=='R'){
              tmp[nxtx][nxty]='P';
            }
          }
        }
      }
    }
  }
  Board=tmp;
}
int main(){
  int T;
  string row;
  scanf("%d",&T);
  getchar();
  while(T--){
    Board.clear();
    scanf("%d %d %d",&r,&c,&n);
    R(i,0,r,1){
      cin>>row;
      Board.push_back(row);
    }
    R(i,0,n,1){
      Attack();
    }
    printBoard();
    if(T)
      putchar('\n');
  }
}
