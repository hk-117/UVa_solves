#include<bits/stdc++.h>
#define MX 101
using namespace std;
int main(){
  int M,tc=0,Unit,Un;
  while(scanf("%d.%d %d",&Unit,&Un,&M)==3){
    int UnitP=Unit*100+Un;
    vector<int> dp(MX,UnitP);
    for(int i=1;i<MX;i++){
      dp[i]=UnitP*i;
    }
    int itm,price,p,pr;
    for(int i=0;i<M;i++){
      scanf("%d %d.%d",&itm,&p,&pr);
      UnitP=p*100+pr;
      price=UnitP;
      int j=itm;
      if(dp[j]>price){
        dp[j]=price;
        int k=j-1;
        while(dp[k]>price && k){
          dp[k]=price;
          k--;
        }
      }
    }
    for(int i=1;i<MX;i++){
      for(int j=i;j>=1;j--){
        dp[i]=min(dp[i],dp[i-j]+dp[j]);
      }
    }
    getchar();
    string line;
    getline(cin,line);
    printf("Case %d:\n",++tc);
    stringstream sin(line);
    while(sin>>itm){
      printf("Buy %d for $%.2lf\n",itm,dp[itm]/100.0);
    }
  }
}
