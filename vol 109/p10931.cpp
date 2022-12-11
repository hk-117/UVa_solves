#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  while(cin>>N,N){
    bitset<32> B(N);
    string Bin=B.to_string();
    while(Bin[0]=='0'){
      Bin.erase(Bin.begin());
    }
    cout<<"The parity of "<<Bin<<" is "<<B.count() <<" (mod 2)."<<endl;
  }
}
