#include<stdio.h>
#include<math.h>
int main(){
  int H,M;
  double Angl,HtoM,dist;
  while(scanf("%d:%d",&H,&M)==2 &&(H||M)){
    HtoM=(1.0/12.0)*(double)M + H*5 - M;
    HtoM=fabs(HtoM);
    Angl=HtoM*6;
    if(360-Angl < Angl){
      printf("%.3lf\n",360-Angl);
    }
    else
      printf("%.3lf\n",Angl);
  }
}
