#include<bits/stdc++.h>
using namespace std;
string digits="VUCD";
string Add(string c1,string c2){
  string res;
  int len1=c1.size(),len2=c2.size(),mx=max(len1,len2);
  if(len1<mx){
    for(int i=1;i<=mx-len1;i++) c1.insert(0,"0");
  }
  else{
    for(int i=1;i<=mx-len2;i++) c2.insert(0,"0");
  }
  int carry=0;
  for(int i=mx-1;i>=0;i--){
    int d= ((c1[i]-'0')+(c2[i]-'0')+carry)/4;
    res+= ((c1[i]-'0')+(c2[i]-'0')+carry)-4*d +'0';
    carry=d;
  }
  if(carry > 0)
    res+= carry+'0';
  reverse(res.begin(),res.end());
  return res;
}
int main(){
  int N;
  cin>>N;
  cin.ignore();
  cout<<"COWCULATIONS OUTPUT"<<endl;
  while(N--){
    string n1,n2,fin,c1,c2;
    char op[3];
    cin>>n1>>n2>>op[0]>>op[1]>>op[2]>>fin;
    for(int i=0;i<5;i++){
      if(n1[i]=='V') c1+='0';
      if(n2[i]=='V') c2+='0';
      if(n1[i]=='U') c1+='1';
      if(n2[i]=='U') c2+='1';
      if(n1[i]=='C') c1+='2';
      if(n2[i]=='C') c2+='2';
      if(n1[i]=='D') c1+='3';
      if(n2[i]=='D') c2+='3';
    }
    for(int i=0;i<3;i++){
      if(op[i]=='A'){
        c2= Add(c1,c2);
      }
      else if(op[i]=='R'){
        c2.erase(c2.size()-1);
        c2.insert(0,"0");
      }
      else if(op[i]=='L'){
        c2+='0';
      }
      else{
        //nothing
      }
    }
    n2="";
    for(int i=1;i<=(8-c2.size());i++){
      n2+=digits[0];
    }
    for(int i=0;i<c2.size();i++){
      n2+= digits[c2[i]-'0'];
    }
    if(n2== fin){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  cout<<"END OF OUTPUT"<<endl;
}
