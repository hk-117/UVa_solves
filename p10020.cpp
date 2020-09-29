#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
typedef long long ll;
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int M,L,R;
    vector<pair<int,int>>intervals;
    scanf("%d",&M);
    while(scanf("%d %d",&L,&R)==2 && (L||R)){
      intervals.push_back(make_pair(L,R));
    }
    sort(intervals.begin(),intervals.end());
    bool possible=false;
    int ch,i,j;
    int Right=0;
    vector<int> sol;
    for(i=0,j=0;i<intervals.size();i++){
      ll tmp=Right;
      ch=-1;
      while(j<intervals.size() && intervals[j].first<=Right){
        if(intervals[j].second>tmp){
          tmp=intervals[j].second;
          ch=j;
        }
        j++;
      }
      sol.push_back(ch);
      if(tmp>=M){
        printf("%d\n",(i+1));
        possible=true;
        for(int k=0;k<sol.size();k++){
          printf("%d %d\n",intervals[sol[k]].first,intervals[sol[k]].second);
        }
        break;
      }
      if(ch==-1)
        break;
      Right=tmp;
    }
    if(!possible)
      puts("0");
    if(T)
      putchar('\n');
  }
}
