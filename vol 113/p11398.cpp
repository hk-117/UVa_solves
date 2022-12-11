#include<bits/stdc++.h>
using namespace std;
int main(){
  string line;
  bool whole_break=false;
  while(!whole_break){
    string cs;
    while(getline(cin,line)){
      if(line[line.size()-1] == '#'){
        cs+= line;
        break;
      }
      if(line=="~"){
        whole_break=true;
        break;
      }
      cs+= line+ " ";
    }
    if(!whole_break){
      stringstream ss(cs);
      string block,ans;
      char flg;
      while(ss>>block,block!="#"){
        if(block.size()==1){
          flg='1';
        }
        else if(block.size()==2){
          flg='0';
        }
        else{
          int d= block.size()-2;
          for(int i=1;i<=d;i++)
            ans+= flg;
        }
      }
      long long N= strtol(ans.c_str(),NULL,2);
      cout<< N <<endl;
    }
  }
}
