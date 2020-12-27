#include<bits/stdc++.h>
using namespace std;
string sqn=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char,int> Pos;
void makeMap(){
  for(int i=0;i<sqn.size();i++){
    Pos[sqn[i]]=i;
  }
}
int main(){
  map<string,bool> D;
  string w,msg,dec;
  int bstk,mxm=-1,mcnt;
  makeMap();
  while(cin>>w,w!="#"){
    D[w]=true;
  }
  string tmp;
  getchar();
  getline(cin,msg);
  for(int i=1;i<=26;i++){
    dec="";
    for(int j=0;j<msg.size();j++){
      dec+= sqn[(Pos[msg[j]]+i)%27];
    }
    stringstream ss(dec);
    mcnt=0;
    while(ss>>tmp){
      if(D[tmp]){
        mcnt++;
      }
    }
    if(mcnt>mxm){
      mxm=mcnt;
      bstk=i;
    }
  }
  dec="";
  for(int j=0;j<msg.size();j++){
    dec+= sqn[(Pos[msg[j]]+bstk)%27];
  }
  stringstream ss(dec);
  int lineSize=0;
  while(ss>>tmp){
    if(lineSize+tmp.size()>59){
      cout<<"\n"<<tmp;
      lineSize=tmp.size();
    }
    else{
      if(!lineSize){
        cout<<tmp;
        lineSize+=tmp.size();
      }
      else{
        cout<<" "<<tmp;
        lineSize+=tmp.size()+1;
      }
    }
  }
  cout<<endl;
}
