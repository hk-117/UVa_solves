#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  while(N--){
    int Q;
    cin>>Q;
    int D=9;
    vector<int> factors;
    if(Q<=D){
      printf("%d\n",Q);
      continue;
    }
    while(Q>9 && D>1){
      while(Q%D==0){Q/=D;factors.push_back(D);}
      D--;
    }
    if(Q>9)
      printf("-1\n");
    else{
      if(Q>1) factors.push_back(Q);
      for(int i=factors.size()-1;i>=0;i--){
        printf("%d",factors[i]);
      }
      puts("");
    }
  }
}
