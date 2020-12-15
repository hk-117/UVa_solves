#include<bits/stdc++.h>
using namespace std;
int main(){
  string line;
  while(true){
    getline(cin,line);
    if(line=="#")
      break;
    map<string,bool> Exposed;
    int counter=0;
    vector<string> Piles[13];
    stringstream ss(line);
    string tmp,cur;
    for(int i=12;i>=0;i--){
      ss>>tmp;
      Piles[i].push_back(tmp);
    }
    for(int i=1;i<=3;i++){
      getline(cin,line);
      stringstream ins(line);
      for(int j=12;j>=0;j--){
        ins>>tmp;
        Piles[j].push_back(tmp);
      }
    }
    tmp=Piles[12][0];
    cur=tmp;
    Piles[12].erase(Piles[12].begin());
    while(!Exposed[tmp]){
      counter++;
      Exposed[tmp]=true;
      if(tmp[0]=='A'){
        Piles[0].push_back(tmp);
        cur=tmp;
        tmp=Piles[0][0];
        Piles[0].erase(Piles[0].begin());
      }
      else if(tmp[0]=='T'){
        Piles[9].push_back(tmp);
        cur=tmp;
        tmp=Piles[9][0];
        Piles[9].erase(Piles[9].begin());
      }
      else if(tmp[0]=='J'){
        Piles[10].push_back(tmp);
        cur=tmp;
        tmp=Piles[10][0];
        Piles[10].erase(Piles[10].begin());
      }
      else if(tmp[0]=='Q'){
        Piles[11].push_back(tmp);
        cur=tmp;
        tmp=Piles[11][0];
        Piles[11].erase(Piles[11].begin());
      }
      else if(tmp[0]=='K'){
        Piles[12].push_back(tmp);
        cur=tmp;
        tmp=Piles[12][0];
        Piles[12].erase(Piles[12].begin());
      }
      else{
        int pos= tmp[0]-'0'-1;
        Piles[pos].push_back(tmp);
        cur=tmp;
        tmp=Piles[pos][0];
        Piles[pos].erase(Piles[pos].begin());
      }
    }
    printf("%02d,%s\n",counter,cur.data());
  }
}
