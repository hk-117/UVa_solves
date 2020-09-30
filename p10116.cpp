#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
typedef pair<int,int> ii;
enum Directions{N,S,E,W};
int px[]={-1,1,0,0},py[]={0,0,1,-1};
int C,R,Start;
bool isValidMove(int x,int y){
  if(x>=R || x<0 || y>=C || y<0)
    return false;
  return true;
}
int main(){
  int Stp;
  while(cin>>R>>C>>Start,(R||C||Start)){
    string Wrld[R];
    R(i,0,R,1){
      cin>>Wrld[i];
    }
    map<ii,int> MemStp;
    bool Proceed=true,loop=false;
    int x=0,y=Start-1,loopAtStep;
    Stp=0;
    while(Proceed){
      Stp++;
      MemStp[make_pair(x,y)]=Stp;
      if(Wrld[x][y]=='N'){
        int newx=x+px[N],newy=y+py[N];
        if(!isValidMove(newx,newy)){
          Proceed=false;
        }
        else{
          if(MemStp[make_pair(newx,newy)]>0){
            Proceed=false;
            loop=true;
            loopAtStep=MemStp[make_pair(newx,newy)];
          }
          else{
            x=newx;
            y=newy;
          }
        }
      }
      else if(Wrld[x][y]=='S'){
        int newx=x+px[S],newy=y+py[S];
        if(!isValidMove(newx,newy)){
          Proceed=false;
        }
        else{
          if(MemStp[make_pair(newx,newy)]>0){
            Proceed=false;
            loop=true;
            loopAtStep=MemStp[make_pair(newx,newy)];
          }
          else{
            x=newx;
            y=newy;
          }
        }
      }
      else if(Wrld[x][y]=='E'){
        int newx=x+px[E],newy=y+py[E];
        if(!isValidMove(newx,newy)){
          Proceed=false;
        }
        else{
          if(MemStp[make_pair(newx,newy)]>0){
            Proceed=false;
            loop=true;
            loopAtStep=MemStp[make_pair(newx,newy)];
          }
          else{
            x=newx;
            y=newy;
          }
        }
      }
      else{
        int newx=x+px[W],newy=y+py[W];
        if(!isValidMove(newx,newy)){
          Proceed=false;
        }
        else{
          if(MemStp[make_pair(newx,newy)]>0){
            Proceed=false;
            loop=true;
            loopAtStep=MemStp[make_pair(newx,newy)];
          }
          else{
            x=newx;
            y=newy;
          }
        }
      }
    }
    if(!loop){
      cout<<Stp<<" step(s) to exit"<<endl;
    }
    else{
      cout<< loopAtStep-1 <<" step(s) before a loop of "<< Stp-(loopAtStep-1)<<" step(s)"<<endl;
    }
  }
}
