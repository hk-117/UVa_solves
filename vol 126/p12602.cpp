#include<bits/stdc++.h>
using namespace std;
int main(){
  int D,t;
  string line;
  cin>>t;
  cin.ignore();
  while(t--){
    getline(cin,line);
    string H(line.begin(),line.begin()+3),tmp(line.begin()+4,line.end());
    int Cnv=0;
    D= atoi(tmp.c_str());
    for(int i=0;i<3;i++){
      int pos= 3-i-1;
      Cnv+= (H[i]-'A')* pow(26,pos);
    }
    if(abs(Cnv-D)<=100)
      puts("nice");
    else
      puts("not nice");
  }
}
