#include<bits/stdc++.h>
#define DEST 100
using namespace std;
int main(){
  int Players,Throw,Board[101];
  vector<int> Throws;
  while(cin>>Throw,Throw){
    Throws.push_back(Throw);
  }
  while(cin>>Players,Players){
    memset(Board,0,sizeof Board);
    int pos1,pos2;
    while(cin>>pos1>>pos2,pos1&&pos2){
      Board[pos1]=pos2;
    }
    int posVal;
    while(cin>>posVal,posVal){
      if(posVal<0){
        Board[-posVal]=-1;
      }
      else{
        Board[posVal]=-2;
      }
    }
    vector<int> P(Players,0),Status(Players,0);
    int Gover=0,Turn=0;
    for(int i=0;i<Throws.size() && !Gover;i++){
      if(Status[Turn]==-1){
        Turn++;
        Status[Turn]=0;
      }
      else{
        if(P[Turn]+Throws[i]<=100){
          P[Turn]+=Throws[i];
          if(P[Turn]==100){
            Gover=Turn;
          }
          else if(Board[P[Turn]]==-1){
            Status[Turn]=-1;
            Turn++;
          }
          else if(Board[P[Turn]]==-2){
            Turn=Turn;
          }
          else{
            if(Board[P[Turn]]!=0){
              P[Turn]=Board[P[Turn]];
              Turn++;
            }
            else
              Turn++;
          }
        }
        else{
          Turn++;
        }
        if(Turn>Players-1) Turn=0;
      }
    }
    printf("%d\n",Gover+1);
  }
}
