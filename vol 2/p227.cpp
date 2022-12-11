#include<bits/stdc++.h>
using namespace std;
string Puzzle[5];
int movx[4]={-1,1,0,0},movy[4]={0,0,-1,1},Bx,By,T;
bool posFound,nl=false,legal;
void findPos(string row,int rowN){
  for(int i=0;i<5;i++){
    if(row[i]==' '){
      posFound=true;
      Bx=rowN;
      By=i;
    }
  }
}
void movPos(){
  if((Bx<0||Bx>=5)||(By<0||By>=5))
    legal=false;
}
void followInstructions(string Ins){
  int curx,cury;
  for(int i=0;i<Ins.size()-1 && legal;i++){
   curx=Bx,cury=By; 
   if(Ins[i]=='A'){
      Bx=Bx+movx[0];
      By=By+movy[0];
      movPos();
      if(legal){
        swap(Puzzle[curx][cury],Puzzle[Bx][By]);
      }
    }
    else if(Ins[i]=='B'){
      Bx=Bx+movx[1];
      By=By+movy[1];
      movPos();
      if(legal){
        swap(Puzzle[curx][cury],Puzzle[Bx][By]);
      }
    }
    else if(Ins[i]=='L'){
      Bx=Bx+movx[2];
      By=By+movy[2];
      movPos();
      if(legal){
        swap(Puzzle[curx][cury],Puzzle[Bx][By]);
      }
    }
    else if(Ins[i]=='R'){
      Bx=Bx+movx[3];
      By=By+movy[3];
      movPos();
      if(legal){
        swap(Puzzle[curx][cury],Puzzle[Bx][By]);
      }
    }
    else{
      legal=false;
    }
  }
}
void printPuzzle(){
  T++;
  if(nl)
    putchar('\n');
  else
    nl=true;
  printf("Puzzle #%d:\n",T);
  if(!legal){
    puts("This puzzle has no final configuration.");
    return;
  }
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      putchar(Puzzle[i][j]);
      if(j!=4)
        putchar(' ');
    }
    putchar('\n');
  }
}
int main(){
  string line;
  while(true){
    getline(cin,line);
    if(line=="Z"){
      break;
    }
    else{
      posFound=false;
      legal=true;
      Puzzle[0]=line;
      findPos(line,0);
      for(int i=1;i<=4;i++){
        getline(cin,Puzzle[i]);
        if(!posFound)
          findPos(Puzzle[i],i);
      }
      string command;
      while(getline(cin,line)){
        if(line[line.size()-1]=='0'){
          command+=line;
          followInstructions(command);
          break;
        }
        else{
          command+=line;
        }
      }
      printPuzzle();
    }
  }
}
