#include<bits/stdc++.h>
using namespace std;

int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
int Dim;
vector<string> grid;

int floodfill(int r,int c,char c1,char c2){
  if(r<0||r>=Dim||c<0||c>=Dim) return 0;
  if(grid[r][c]!=c1) return 0;
  int ans=1;
  grid[r][c]=c2;
  for(int d=0;d<8;d++)
    ans+=floodfill(r+dr[d],c+dc[d],c1,c2);
  return ans;
}

int main(){
  int img=0;
  while(cin>>Dim){
    int eagles=0;
    string line;
    for(int i=0;i<Dim;i++){
      cin>>line;
      grid.push_back(line);
    }
    for(int i=0;i<Dim;i++){
      for(int j=0;j<Dim;j++){
        if(grid[i][j]=='1'){
          eagles++;
          int tmp=floodfill(i,j,'1','0');
        }
      }
    }
    printf("Image number %d contains %d war eagles.\n",++img,eagles);
    grid.clear();
  }
}
