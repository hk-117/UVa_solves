#include<bits/stdc++.h>
using namespace std;
int M,N;
vector<string> grid;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int floodfill(int r,int c,char c1,char c2){
  if(r>=M||r<0||c>=N||c<0) return 0;
  if(grid[r][c]!=c1) return 0;
  grid[r][c]=c2;
  int ans=1;
  for(int i=0;i<4;i++){
    if(c+dc[i]==N){
      ans+= floodfill(r+dr[i],0,c1,c2);
    }
    else if(c+dc[i]==-1){
      ans+= floodfill(r+dr[i],N-1,c1,c2);
    }
    else{
      ans+= floodfill(r+dr[i],c+dc[i],c1,c2);
    }
  }
  return ans;
}
int main(){
  int x,y;
  while(cin>>M>>N){
    string line;
    for(int i=0;i<M;i++){
      cin>>line;
      line+=line[0];
      grid.push_back(line);
    }
    cin>>x>>y;
    char land=grid[x][y];
    int mx=0;
    int tmp=floodfill(x,y,land,'0');
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        if(grid[i][j]==land){
          mx=max(mx,floodfill(i,j,land,'0'));
        }
      }
    }
    printf("%d\n",mx);
    grid.clear();
  }
}
