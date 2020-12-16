#include<bits/stdc++.h>
using namespace std;
vector<int> CorrectOrder;
map<int,int> OrderIndex;
void makeIndex(){
  OrderIndex.clear();
  vector<int> T(CorrectOrder);
  for(int i=0;i<CorrectOrder.size();i++){
    T[CorrectOrder[i]-1]=1+i;
  }
  CorrectOrder=T;
  for(int i=0;i<CorrectOrder.size();i++){
    OrderIndex[CorrectOrder[i]]=i+1;
  }
}
int pointObtained(int N,vector<int> A){
  int length[N],mx=INT_MIN;
  vector<int> T(A);
  for(int i=0;i<N;i++){
    T[A[i]-1]=1+i;
  }
  A=T;
  for(int i=0;i<N;i++){
    length[i]=1;
    for(int j=0;j<i;j++){
      if(OrderIndex[A[j]]<OrderIndex[A[i]]){
        length[i]=max(length[i],length[j]+1);
      }
    }
    mx=max(mx,length[i]);
  }
  return mx;
}
int main(){
  string line;
  vector<int> tmp;
  int N;
  while(getline(cin,line)){
    if(line.size()<=2){
      N=atoi(line.c_str());
      getline(cin,line);
      stringstream ss(line);
      tmp.clear();
      int in;
      while(ss>>in){
        tmp.push_back(in);
      }
      CorrectOrder=tmp;
      makeIndex();
    }
    else{
      stringstream ss(line);
      tmp.clear();
      int in;
      while(ss>>in){
        tmp.push_back(in);
      }
      printf("%d\n",pointObtained(N,tmp));
    }
  }
}
