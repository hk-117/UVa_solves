#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
  int N;
  while(scanf("%d",&N)==1){
    int total=0,Mat[N][N];
    R(i,0,N,1){
      R(j,0,N,1){
        scanf("%d",&Mat[i][j]);
      }
    }
    R(i,0,N,1){
      R(j,0,N,1){
        R(k,0,N,1){
          if(i==j && j==k)
            continue;
          if(Mat[i][j] && Mat[j][k] && Mat[k][i]){
            if((i<j && j<k) || (i>j && j>k)){
              printf("%d %d %d\n",i+1,j+1,k+1);
              total++;
            }
          }
        }
      }
    }
    printf("total:%d\n",total);
    putchar('\n');
  }
}
