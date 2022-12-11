#include<bits/stdc++.h>
using namespace std;
int main(){
  int C,S,tc=0;
  while(scanf("%d %d",&C,&S)==2){
    vector<pair<int,int>> sp(2*C,pair<int,int>(0,0)),dm;
    double avg=0.0;
    for(int i=0;i<S;i++){
      scanf("%d",&sp[i].first);
      sp[i].second=i;
      avg+= sp[i].first;
    }
    for(int i=S;i<2*C;i++){
      sp[i].first=0;
      sp[i].second=i;
    }
    avg= avg/(double)C;
    dm=sp;
    sort(sp.begin(),sp.end());
    printf("Set #%d\n",++tc);
    double t=0.0;
    vector<pair<int,int>> chem(C);
    for(int i=0;i<C;i++){
      t+=fabs((sp[i].first+sp[2*C-i-1].first)-avg);
      if(sp[i].second > sp[2*C-i-1].second){
        chem[i]=make_pair(sp[2*C-i-1].second,sp[i].second);
      }
      else{
        chem[i]=make_pair(sp[i].second,sp[2*C-i-1].second);
      }
    }
    sort(chem.begin(),chem.end());
    for(int i=0;i<C;i++){
      printf("%2d:",i);
      if(dm[chem[i].first].first!=0){
        printf(" %d",dm[chem[i].first].first);
      }
      if(dm[chem[i].second].first!=0){
        printf(" %d",dm[chem[i].second].first);
      }
      puts("");
    }
    printf("IMBALANCE = %.5lf\n",t);
    puts("");
  }
}
