#include<bits/stdc++.h>
#define MAX_N 100
using namespace std;
string T,P;
int b[MAX_N],n,m;

void kmpPreprocess(){
  int i=0,j=-1;
  b[0]=-1;
  while(i<m){
    while(j>=0 && P[i]!=P[j]) {
      j=b[j];
    }
    i++;j++;
    b[i]=j;
  }
}

int kmpSearch(){
  int i=0,j=0,cnt=0;
  while(i<n){
    while(j>=0 && T[i]!=P[j]){ 
      j=b[j];
    }
    i++;j++;
    if(j==m){
      cnt++;
      j=0;
    }
  }
  return cnt;
}

int main(){
  int Ts;
  cin>>Ts;
  cin.ignore();
  while(Ts--){
    cin>>T;
    cin.ignore();
    n=T.size();
    int cnt;
    for(m=1;m<=n;m++){
      P.assign(T,0,m);
      kmpPreprocess();
      cnt=kmpSearch();
      if(cnt*m==n){
        cout<<m<<endl;
        if(Ts)
          cout<<endl;
        break;
      }
    }
  }
}
