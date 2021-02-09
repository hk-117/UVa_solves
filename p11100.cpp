#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  bool nl=false;
  while(scanf("%d",&N)==1 && N){
    vector<int> Pcs(N);
    map<int,int> Cont;
    int maxK=-1;
    if(nl)
      printf("\n");
    else
      nl=true;
    for(int i=0;i<N;i++){
      scanf("%d",&Pcs[i]);
      Cont[Pcs[i]]++;
      maxK=max(maxK,Cont[Pcs[i]]);
    }
    printf("%d\n",maxK);
    sort(Pcs.begin(),Pcs.end());
    for(int i=0;i<maxK;i++){
      printf("%d",Pcs[i]);
      for(int j=i+maxK;j<N;j+=maxK){
        printf(" %d",Pcs[j]);
      }
      printf("\n");
    }
  }
}
