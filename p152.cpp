#include<bits/stdc++.h>
#define EPS 1e-9
using namespace std;
struct TDP{
  double x,y,z;
  TDP(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
  bool operator <(TDP other) const{
    if(fabs(x-other.x)<EPS){
      if(fabs(y-other.y)<EPS){
        return z<other.z;
      }
      else{
        return y<other.y;
      }
    }
    else
      return x<other.x;
  }
};
double hypotTDP(double a,double b,double c){
  return sqrt(a*a+b*b+c*c);
}
double distTDP(TDP a,TDP b){
  return hypotTDP(a.x-b.x,a.y-b.y,a.z-b.z);
}
int cnt[10];
int main(){
  double x,y,z,tmp,mn;
  vector<TDP> T;
  while(scanf("%lf%lf%lf",&x,&y,&z)==3 && (x||y||z)){
    T.push_back(TDP(x,y,z));
  }
  sort(T.begin(),T.end());
  for(int i=0;i<T.size();i++){
    mn=INT_MAX;
    for(int j=0;j<T.size();j++){
      if(i!=j){
        tmp=distTDP(T[i],T[j]);
        mn=min(mn,tmp);
      }
    }
    if(mn<10){
      cnt[(int) mn]+=1;
    }
  }
  for(int i=0;i<10;i++){
    printf("%4d",cnt[i]);
  }
  printf("\n");
}
