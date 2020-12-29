#include<bits/stdc++.h>
using namespace std;
void Decode(string L,vector<int> T,int pri){
  int index = pri;
  for(int i = 0 ; i < T.size() ; i++ ){
    index = T[ index ];
    cout << L[ index ];
  }
  cout<<endl;
}
vector<int> getTransform(string A){
  string B=A;
  sort(B.begin(),B.end());
  vector<bool> Taken(B.size(),false);
  vector<int> T(B.size());
  for(int i=0;i<A.size();i++){
    for(int j=0;j<B.size();j++){
      if(!Taken[j] && A[i]==B[j]){
        Taken[j]=true;
        T[j]=i;
        break;
      }
    }
  }
  return T;
}
int main(){
  int n;
  string Inp;
  bool nl=false;
  while(cin>>Inp>>n,Inp!="END" && n!=0){
    vector<int> T;
    T=getTransform(Inp);
    if(nl)
      putchar('\n');
    else
      nl=true;
    Decode(Inp,T,n-1);
  }
}
