#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;
int main(){
  double l,w,h,Tht,vol,mvol,llen;
  while(scanf("%lf %lf %lf %lf",&l,&w,&h,&Tht)==4){
    vol= l*w*h;
    llen=l* tan(pi*Tht/180.0);
    if(llen> h){
      Tht=90-Tht;
      llen= h* tan(pi*Tht/180.0);
      mvol=0.5* llen * h * w;
      printf("%.3lf mL\n",mvol);
    }
    else{
      mvol= 0.5 * l * llen * w;
      printf("%.3lf mL\n",vol-mvol);
    }
  }
}
