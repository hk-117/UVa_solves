#include<bits/stdc++.h>
using namespace std;

int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
int R,C;
vector<string> grid;

int floodfill(int r,int c,char c1,char c2){
  if(r<0||r>=R||c<0||c>=C) return 0;
  if(grid[r][c]!=c1) return 0;
  int ans=1;
  grid[r][c]=c2;
  for(int d=0;d<8;d++)
    ans+=floodfill(r+dr[d],c+dc[d],c1,c2);
  return ans;
}

int main(){
  int T;
  cin>>T;
  cin.ignore();
  cin.ignore();
  while(T--){
    string line;
    int r,c;
    R=0;
    C=0;
    vector<string>tmp;
    while(getline(cin,line),line.size()){
      if(line[0]=='W'||line[0]=='L'){
        if(!C) C=line.size();
        tmp.push_back(line);
      }
      else{
        grid=tmp;
        if(!R) R=grid.size();
        sscanf(line.c_str(),"%d %d",&r,&c);
        printf("%d\n",floodfill(r-1,c-1,'W','.'));
      }
    }
    if(T)
      puts("");
  }
}
