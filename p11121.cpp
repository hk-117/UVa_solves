#include<bits/stdc++.h>
using namespace std;
string negaBinary(int value){
  string res;
  while(value){
    int dr= value/(-2);
    int rem= value % (-2);
    if(rem<0){
      value = dr+1;
    }
    else{
      value= dr;
    }
    if(rem!=0){
      res+="1";
    }
    else
      res+="0";
  }
  if(res.length()==0)
    return "0";
  reverse(res.begin(),res.end());
  return res;
}
int main(){
  int T,tc=0,N;
  cin>>T;
  while(T--){
    cin>>N;
    string A= negaBinary(N);
    cout<<"Case #"<< ++tc <<": "<<A<<endl;
  }
}
