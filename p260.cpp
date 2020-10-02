#include<bits/stdc++.h>
using namespace std;

int dr[]={-1,-1,0,0,1,1};
int dc[]={-1,0,-1,1,0,1};
int N;
vector<string> grid;

int floodfill(int r,int c,char c1,char c2){
  if(r<0||r>=N||c<0||c>=N) return 0;
  if(grid[r][c]!=c1) return 0;
  int ans=1;
  grid[r][c]=c2;
  for(int d=0;d<6;d++)
    ans+=floodfill(r+dr[d],c+dc[d],c1,c2);
  return ans;
}

bool chkBlackWin(vector<string> &tmp){
  for(int i=0;i<N;i++){
    if(tmp[N-1][i]=='b' && grid[N-1][i]=='w')
      return true;
  }
  return false;
}

bool chkWhiteWin(vector<string> &tmp){
  for(int i=0;i<N;i++){
    if(tmp[i][N-1]=='w' && grid[i][N-1]=='b')
      return true;
  }
  return false;
}

int main(){
  int gm=0;
  while(cin>>N,N){
    vector<string>tmp;
    string row;
    for(int i=0;i<N;i++){
      cin>>row;
      tmp.push_back(row);
    }
    //check black win
    bool b_win=false;
    for(int i=0;i<N && !b_win;i++){
      grid=tmp;
      if(grid[0][i]=='b'){
        floodfill(0,i,'b','w');
        b_win=chkBlackWin(tmp);
      }
    }
    //check white win
    bool w_win=false;
    for(int i=0;i<N && !b_win && !w_win;i++){
      grid=tmp;
      if(grid[i][0]=='w'){
        floodfill(i,0,'w','b');
        w_win=chkWhiteWin(tmp);
      }
    }
    if(w_win){
      printf("%d W\n",++gm);
    }
    else{
      printf("%d B\n",++gm);
    }
  }
}
