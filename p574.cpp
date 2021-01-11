#include<bits/stdc++.h>
using namespace std;
int N,T,sz,List[15],tmpList[15];
bool found;
set<vector<int>> Solvs;
void SM(int i,int S){
  if(S==T){
    found=true;
    vector<int> tmp(tmpList,tmpList+sz);
    if(Solvs.find(tmp)!=Solvs.end())
      return;
    printf("%d",tmpList[0]);
    for(int j=1;j<sz;j++){
      printf("+%d",tmpList[j]);
    }
    printf("\n");
    Solvs.insert(tmp);
    return;
  }
  if(S>T || i>=N)
    return;
  tmpList[sz++]=List[i];
  SM(i+1,S+List[i]);
  sz--;
  SM(i+1,S);
}
int main(){
  int i;
  while(scanf("%d %d",&T,&N)==2 && (N!=0)){
    for(i=0;i<N;i++){
      scanf("%d",&List[i]);
    }
    printf("Sums of %d:\n",T);
    found=false;
    SM(0,0);
    if(!found)
      printf("NONE\n");
    Solvs.clear();
  }
}
