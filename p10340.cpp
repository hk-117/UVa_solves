#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  while(cin>>s>>t){
    bool P=true;
    int sS=s.size(),tS=t.size(),i,j,lastPos=0;
    for(i=0;i<sS && P;i++){
      for(j=lastPos;j<tS && P;j++){
        if(t[j]==s[i]){
          lastPos=j+1;
          break;
        }
        else{
          if(j==tS-1)
            P=false;
        }
      }
    }
    if(P)
      puts("Yes");
    else
      puts("No");
  }
}
