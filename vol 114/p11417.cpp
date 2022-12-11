#include<cstdio>
using namespace std;
int gcd(int a,int b){
  return (b==0 ? a:gcd(b,a%b));
}
int main(){
  int N;
  while(scanf("%d",&N)==1 && N){
    int i,j,G=0;
    for(i=1;i<N;i++){
      for(j=i+1;j<=N;j++){
        G+=gcd(j,i);
      }
    }
    printf("%d\n",G);
  }
}
