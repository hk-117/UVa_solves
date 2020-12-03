#include<bits/stdc++.h>
using namespace std;
bool Avail[80],LVB[5][5];
vector<pair<int,int>> AvailPos(80);
int BINGO[5][5];
bool GameFinished(){
  bool status;
  for(int i=0;i<5;i++){
    status=true;
    for(int j=0;j<5;j++){
      if(!LVB[i][j])
        status=false;
    }
    if(status)
      return status;
  }
  for(int i=0;i<5;i++){
    status=true;
    for(int j=0;j<5;j++){
      if(!LVB[j][i])
        status=false;
    }
    if(status)
      return status;
  }
  if(LVB[0][4]&&LVB[1][3]&&LVB[2][2]&&LVB[3][1]&&LVB[4][0])
    return true;
  if(LVB[0][0]&&LVB[1][1]&&LVB[2][2]&&LVB[3][3]&&LVB[4][4])
    return true;
  return false;
}
int main(){
  int N;
  scanf("%d",&N);
  while(N--){
    memset(Avail,0,sizeof Avail);
    memset(LVB,0,sizeof LVB);
    LVB[2][2]=true;
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        if(i==2 && j==2)
          continue;
        scanf("%d",&BINGO[i][j]);
        Avail[BINGO[i][j]]=true;
        AvailPos[BINGO[i][j]]=make_pair(i,j);
      }
    }
    int tmp;
    bool finished=false;
    for(int i=1;i<=75;i++){
      scanf("%d",&tmp);
      if(Avail[tmp] && !finished){
        pair<int,int> Atmp=AvailPos[tmp];
        LVB[Atmp.first][Atmp.second]=true;
        if(GameFinished()){
          finished=true;
          printf("BINGO after %d numbers announced\n",i);
        }
      }
    }
  }
}
