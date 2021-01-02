#include<bits/stdc++.h>
#define MAX_N 1000025
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
  int i=1,j=0,cnt=0;
  while(i<n){
    while(j>=0 && T[i]!=P[j]){ 
      j=b[j];
    }
    i++;j++;
    if(j==m){
      cnt=i-j;
      break;
    }
  }
  return cnt;
}

int main(){
  int cnt;
  while(cin>>P,P!="."){
    m=P.size();
    kmpPreprocess();
    T=P+P;
    n=2*m;
    cnt=kmpSearch();
    cout<< m/cnt <<endl;
  }
}
