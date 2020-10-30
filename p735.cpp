#include<bits/stdc++.h>
using namespace std;
int Scr[62];
map<int,set<vector<int>>> Perm,Comb;
void createScore(){
  for(int i=1;i<=20;i++){
    Scr[i]=i;
    Scr[2*i]=2*i;
    Scr[3*i]=3*i;
  }
  Scr[61]=50;
}
void makeMap(){
  int ttl;
  for(int i=0;i<62;i++){
    for(int j=0;j<62;j++){
      for(int k=0;k<62;k++){
        ttl= Scr[i]+Scr[j]+Scr[k];
        vector<int> p,c;
        p.push_back(Scr[i]);
        p.push_back(Scr[j]);
        p.push_back(Scr[k]);
        c=p;
        sort(c.begin(),c.end());
        Perm[ttl].insert(p);
        Comb[ttl].insert(c);
      }
    }
  }
}
int main(){
  int N;
  createScore();
  makeMap();
  while(scanf("%d",&N)==1 && N>0){
    if(Comb[N].size()){
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",N,(int)Comb[N].size());
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",N,(int)Perm[N].size());
    }
    else{
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",N);
    }
    for(int i=0;i<70;i++) putchar('*');
    putchar('\n');
  }
  puts("END OF OUTPUT");
}
