#include<stdio.h>
#include<math.h>
int gcd(int a,int b){
  return (b==0? a:(gcd(b,a%b)));
}
int main(){
  int N,NM[55],i,j;
  while(scanf("%d",&N)==1 && N){
    int Pairs=0,NCF=0;
    double est;
    for(i=0;i<N;i++){
      scanf("%d",&NM[i]);
    }
    for(i=0;i<N;i++){
      for(j=i+1;j<N;j++){
        if(gcd(NM[i],NM[j])==1){
          NCF++;
        }
        Pairs++;
      }
    }
    if(NCF==0){
      puts("No estimate for this data set.");
    }
    else{
      est= sqrt((6.0 * (double) Pairs)/(double) NCF);
      printf("%.6lf\n",est);
    }
  }
}
