#include<bits/stdc++.h>
using namespace std;
int BigMod(string num,int N){
  int res=0;
  for(int i=0;i<num.length();i++)
    res= (res*10 + (int) num[i]-'0')%N;
  return res;
}
bool isLeap(string N){
  if(BigMod(N,400) ==0 )
    return true;
  else if(BigMod(N,100)==0)
    return false;
  else if(BigMod(N,4)==0)
    return true;
  else
    return false;
}
int main(){
  string N;
  bool nl=false;
  while(cin>>N){
    if(nl) puts("");
    else
      nl=true;
    if(isLeap(N)){
      puts("This is leap year.");
      if(BigMod(N,15)==0)
        puts("This is huluculu festival year.");
      if(BigMod(N,55)==0)
        puts("This is bulukulu festival year.");
    }
    else{
      if(BigMod(N,15)==0)
        puts("This is huluculu festival year.");
      else
        puts("This is an ordinary year.");
    }
  }
}
