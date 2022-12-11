#include<bits/stdc++.h>
using namespace std;
string BigNumDiv(string number,int divisor){
  string ans;
  int idx=0;
  int temp=number[idx++]-'0';
  while(temp<divisor){
    temp=temp*10 +(number[idx++]-'0');
  }
  while(number.size()>=idx){
    ans+= (temp/divisor) + '0';
    temp = (temp%divisor)*10 +number[idx++]-'0';
  }
  if(ans.length()==0)
    return "0";
  return ans;
}
int BigMod(string num,int a){
  int res=0;
  for(int i=0;i<num.length();i++){
    res= (res*10 + (int) num[i] -'0')%a ;
  }
  return res;
}
int main(){
  string Q;
  while(cin>>Q,Q[0]!='-'){
    int D=9;
    vector<int> factors;
    if(Q.size()==1){
      cout<<1<<Q<<endl;
      continue;
    }
    while(Q.size()>1 && D>1){
      while(BigMod(Q,D)==0){
        Q=BigNumDiv(Q,D);
        factors.push_back(D);
      }
      D--;
    }
    if(Q.size()>1)
      puts("There is no such number.");
    else{
      int q=atoi(Q.c_str());
      if(q>1) factors.push_back(q);
      for(int i=factors.size()-1;i>=0;i--){
        printf("%d",factors[i]);
      }
      puts("");
    }
  }
}
