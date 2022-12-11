#include<bits/stdc++.h>
using namespace std;
int main(){
  int B,S,c=0;
  while(scanf("%d %d",&B,&S)==2 && (B||S)){
    c++;
    vector<int> Bc(B),Sp(S);
    int mn=INT_MAX;
    for(int i=0;i<B;i++){
      scanf("%d",&Bc[i]);
      if(Bc[i]<mn)
        mn=Bc[i];
    }
    for(int j=0;j<S;j++){
      scanf("%d",&Sp[j]);
    }
    printf("Case %d: ",c);
    if(B<=S){
      puts("0");
    }
    else{
      printf("%d %d\n",B-S,mn);
    }
  }
}
