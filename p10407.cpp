#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  return (b==0? a:(gcd(b,a%b)));
}
int main(){
  string line;
  while(getline(cin,line),line!="0"){
    vector<int> N;
    stringstream ss(line);
    int inp;
    while(ss>>inp,inp!=0){
      N.push_back(inp);
    }
    int sb=N[0];
    for(int i=0;i<N.size();i++){
      N[i]=N[i]-sb;
    }
    int gc=gcd(N[0],abs(N[1]));
    for(int i=2;i<N.size();i++){
      gc=gcd(gc,abs(N[i]));
    }
    cout<<gc<<endl;
  }
}
