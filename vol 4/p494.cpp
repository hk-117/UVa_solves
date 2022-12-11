#include<bits/stdc++.h>
using namespace std;
int countWord(string P){
  int cnt=0;
  string wrd;
  for(int i=0;i<P.size();i++){
    if(P[i]>='A' && P[i]<='Z' || P[i]>='a' && P[i]<='z'){
      wrd+=P[i];
    }
    else{
      if(wrd.size()){
        cnt++;
        wrd="";
      }
      else{
        wrd="";
      }
    }
  }
  return cnt;
}
int main(){
  string line;
  while(getline(cin,line)){
    int N=countWord(line);
    printf("%d\n",N);
  }
}
