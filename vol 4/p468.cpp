#include<bits/stdc++.h>
using namespace std;
int main(){
  int C;
  string nen,en;
  scanf("%d",&C);
  getchar();
  getchar();
  while(C--){
    getline(cin,nen);
    getline(cin,en);
    map<char,int> E,NE;
    map<char,char> MP;
    for(int i=0;i<nen.size();i++){
      if((nen[i]>='a' && nen[i]<='z')||(nen[i]>='A' && nen[i]<='Z')){
        NE[nen[i]]++;
      }
    }
    for(int i=0;i<en.size();i++){
      if((en[i]>='a' && en[i]<='z')||(en[i]>='A' && en[i]<='Z')){
        E[en[i]]++;
      }
    }
    vector<pair<int,char>> A,B;
    for(auto it=NE.begin();it!=NE.end();it++){
      A.push_back(make_pair(it->second,it->first));
    }
    for(auto it=E.begin();it!=E.end();it++){
      B.push_back(make_pair(it->second,it->first));
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<B.size();i++){
      MP[B[i].second]=A[i].second;
    }
    for(int i=0;i<en.size();i++){
      printf("%c",MP[en[i]]);
    }
    putchar('\n');
    if(C)
      putchar('\n');
    getchar();
  }
}
