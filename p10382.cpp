#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool cmp(pair<double,double> a,pair<double,double> b){
  return a.first<b.first;
}
int main(){
  int n,l,w;
  while(scanf("%d %d %d",&n,&l,&w)==3){
    vector<pair<double,double>> interval;
    double x,r,dx;
    R(i,0,n,1){
      scanf("%lf %lf",&x,&r);
      if(r > w/2.0){
        dx= sqrt(r*r - (w*w)/4.0);
        interval.push_back(make_pair(x-dx,x+dx));
      }
    }
    sort(interval.begin(),interval.end(),cmp);
    bool possible=false;
    int ch,i,j;
    double Right=0;
    for(i=0,j=0;i<interval.size();i++){
      double tmp=Right;
      ch=-1;
      while(j<interval.size() && interval[j].first<=Right){
        if(interval[j].second>tmp){
          tmp=interval[j].second;
          ch=j;
        }
        j++;
      }
      if(tmp>=l){
        printf("%d\n",i+1);
        possible=true;
        break;
      }
      if(ch==-1)
        break;
      Right=tmp;
    }
    if(!possible)
      puts("-1");
  }
}
