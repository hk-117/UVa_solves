#include<bits/stdc++.h>
using namespace std;
int convertNum(string N,int bs){
  int res=0;
  for(int i=N.size()-1;i>=0;i--){
    res+= (N[i]-'0')* (pow(bs,N.size()-i-1));
  }
  return res;
}
int main(){
  string N;
  while(cin>>N,N!="0"){
    int nm,sq,bs,mx;
    bool found=false;
    mx= *max_element(N.begin(),N.end()) -'0';
    for(bs=mx+1;bs<100 && !found;bs++){
      nm=convertNum(N,bs);
      sq=sqrt(nm);
      if(sq*sq == nm){
        found=true;
      }
    }
    cout<<bs-1<<endl;
  }
}
