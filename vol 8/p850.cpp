#include<bits/stdc++.h>
using namespace std;

string keyMain="the quick brown fox jumps over the lazy dog";
int sizew[]={3,5,5,3,5,4,3,4,3};
map<char,int> F;

map<char,int> makeFreqs(string key){
  map<char,int> Ftmp;
  for(int i=0;i<key.size();i++)
    Ftmp[key[i]]++;
  return Ftmp;
}

bool isSameByWord(string inp){
  stringstream ss(inp);
  int n=0;
  string a;
  while(ss>>a){
    if(a.size() != sizew[n])
      return false;
    n++;
  }
  return true;
}

pair<map<char,char>,bool> mapFoxString(string inp){
  map<char,char> MP;
  map<char,int> nxtFrqs;
  if(isSameByWord(inp)){
    for(int i=0;i<keyMain.size();i++){
      MP[keyMain[i]]=inp[i];
    }
    nxtFrqs=makeFreqs(inp);
    for(char c='a';c<='z';c++){
      if(F[c]!=nxtFrqs[MP[c]])
        return make_pair(MP,false);
    }
    MP.clear();
    for(int i=0;i<keyMain.size();i++)
      MP[inp[i]]=keyMain[i];
    return make_pair(MP,true);
  }
  else
    return make_pair(MP,false);
}

int main(){
  int n;
  scanf("%d",&n);
  getchar();
  getchar();
  F=makeFreqs(keyMain);
  while(n--){
    vector<string> lines;
    string ln;
    pair<map<char,char>,bool> tmp;
    map<char,char> MainMap;
    bool found=false;
    while(getline(cin,ln),ln.size()){
      if(keyMain.size()==ln.size() && !found){
        tmp=mapFoxString(ln);
        if(tmp.second){
          MainMap=tmp.first;
          found=true;
        }
        lines.push_back(ln);
      }
      else{
        lines.push_back(ln);
      }
    }
    for(int i=0;i<lines.size() && found;i++){
      for(int j=0;j<lines[i].size();j++){
        cout<< MainMap[lines[i][j]];
      }
      cout<<endl;
    }
    if(!found)
      cout<<"No solution."<<endl;
    if(n)
      cout<<endl;
  }
}
