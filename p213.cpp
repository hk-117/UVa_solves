#include<bits/stdc++.h>
using namespace std;
map<string,int> IndexOf;
string toBinary(int n){
  string tmp;
  while (n) {
    if (n & 1)
      tmp.insert(0,"1");
    else
      tmp.insert(0,"0");
    n >>= 1;
  }
  return tmp;
}
void indexStringMap(){
  string ix;
  int n=0;
  for(int i=1;i<=7;i++){
    for(int j=0;j<(1<<i)-1;j++){
      ix=toBinary(j);
      int sz=ix.size();
      for(int k=1;k <= i-sz;k++) 
        ix.insert(0,"0");
      IndexOf[ix]=n;
      n++;
    }
  }
}
char readChar(){
  char c;
  while((c=getchar())=='\n' || c=='\r');
  return c;
}
int calcLen(){
  int len=0;
  for(int i=2;i>=0;i--){
    len+= (1<<i)*(readChar()-'0');
  }
  return len;
}
bool isValid(string segMsg){
  for(int i=0;i<segMsg.size();i++){
    if(segMsg[i]=='0')
      return true;
  }
  return false;
}
int main(){
  string H;
  indexStringMap();
  while(getline(cin,H)){
    string Msg;
    int len;
    while(1){
      len=calcLen();
      if(!len) break;
      while(1){
        Msg="";
        for(int i=1;i<=len;i++){
          Msg+= readChar();
        }
        if(isValid(Msg)){
          printf("%c",H[IndexOf[Msg]]);
        }
        else
          break;
      }
    }
    putchar('\n');
    getchar();
  }
}
