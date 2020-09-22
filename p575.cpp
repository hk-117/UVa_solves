#include<bits/stdc++.h>
using namespace std;
int main(){
  string B;
  while(cin>>B,B!="0"){
    long long Ans=0;
    for(int i=B.size()-1;i>=0;i--){
      int p= B.size()-i;
      Ans+= (B[i]-'0') * ((1<<p)-1);
    }
    cout<<Ans<<endl;
  }
}
