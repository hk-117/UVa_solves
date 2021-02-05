#include<bits/stdc++.h>
#define EPS 1e-9
#define R(i,a,b,c) for(i=a;i<b;i+=c)
using namespace std;
int T,CFS[15];
double calcSum(double IRR){
  int i;
  double den=1,sum=0;
  R(i,1,T+1,1){
    den*=(1+IRR);
    sum+=(CFS[i]/den);
  }
  return sum;
}
int main(){
  int i;
  while(scanf("%d",&T)==1 && T){
    double start,end,mid,sum;
    R(i,0,T+1,1){
      scanf("%d",&CFS[i]);
    }
    start=-0.99999;
    end=DBL_MAX;
    while(start <= end+EPS){
      mid=(start+end)/2.0;
      sum=calcSum(mid);
      if(fabs(sum+CFS[0])<=EPS){
        break;
      }
      if(sum+CFS[0] > EPS){
        start=mid;
      }
      else{
        end=mid;
      }
    }
    printf("%.2lf\n",mid);
  }
}
