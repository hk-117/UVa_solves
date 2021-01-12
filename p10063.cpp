#include<bits/stdc++.h>
using namespace std;
int N;
string Str;
queue<string> Q;
void permute(){
  string tmp,out;
  int fSize=Q.front().size();
  while(fSize<N){
    for(int i=0;i<=fSize;i++){
      tmp=Q.front();
      string ins;
      ins+=Str[fSize];
      tmp.insert(i,ins);
      Q.push(tmp);
    }
    Q.pop();
    fSize=Q.front().size();
  }
  while(!Q.empty()){
    printf("%s\n",Q.front().data());
    Q.pop();
  }
}
int main(){
  int nl=0,i;
  while(cin>>Str){
    N=Str.size();
    if(nl)
      puts("");
    else
      nl=1;
    string initial;
    initial+=Str[0];
    Q.push(initial);
    permute();
  }
}
