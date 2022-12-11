#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
  int n,d,r;
  while(scanf("%d %d %d",&n,&d,&r)==3 && (n||d||r)){
    vector<int> Day(n),Night(n);
    R(i,0,n,1){
      scanf("%d",&Day[i]);
    }
    R(i,0,n,1){
      scanf("%d",&Night[i]);
    }
    sort(Day.begin(),Day.end());
    sort(Night.begin(),Night.end(),greater<int>());
    int pay=0;
    R(i,0,n,1){
      if(Day[i]+Night[i]>d){
        pay+= abs((Day[i]+Night[i])-d) * r;
      }
    }
    printf("%d\n",pay);
  }
}
