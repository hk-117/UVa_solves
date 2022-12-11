#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;
bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
  return a.second.first*b.second.second < b.second.first*a.second.second;
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    vector<pair<int,pair<int,int>>> Jobs;
    int N,tm,fine;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
      scanf("%d %d",&tm,&fine);
      Jobs.push_back(make_pair(i,make_pair(tm,fine)));
    }
    stable_sort(Jobs.begin(),Jobs.end(),cmp);
    for(int i=0;i<N;i++){
      printf("%d",Jobs[i].first);
      if(i!=N-1)
        printf(" ");
    }
    putchar('\n');
    if(T)
      putchar('\n');
  }
}
