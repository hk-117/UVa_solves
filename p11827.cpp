#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  return (b==0? a:(gcd(b,a%b)));
}
int main(){
  int tc;
  string line;
  cin>>tc;
  cin.ignore();
  while(tc--){
    vector<int> N;
    getline(cin,line);
    stringstream ss(line);
    int inp;
    while(ss>>inp){
      N.push_back(inp);
    }
    int mx=1;
    for(int i=0;i<N.size();i++){
      for(int j=i+1;j<N.size();j++){
        mx= max(mx,gcd(N[i],N[j]));
      }
    }
    cout<<mx<<endl;
  }
}
