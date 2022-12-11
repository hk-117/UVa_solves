#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  while(scanf("%d",&N)==1 && N){
    multiset<pair<int,int>> S;
    int f,s;
    for(int i=0;i<N;i++){
      scanf("%d %d",&f,&s);
      S.insert(make_pair(f,s));
    }
    bool Possible=true;
    while(Possible && S.size()){
      auto it=S.begin();
      auto fit=S.find(make_pair(it->second,it->first));
      if(fit!=S.end()){
        S.erase(it);
        S.erase(fit);
      }
      else{
        Possible=false;
      }
    }
    if(Possible)
      puts("YES");
    else
      puts("NO");
  }
}
