#include<cstdio>
#include<climits>
#define R(i,a,b,c) for(i=a;i<b;i+=c)
using namespace std;
int T[25],R[25],H[25],TR[25][25],RH[25][25],HT[25][25];
int main(){
  int t,r,h;
  while(scanf("%d %d %d",&t,&r,&h)==3){
    int i,j,k,found=0,mn=INT_MAX,anst,ansr,ansh,tmp;
    R(i,0,t,1){
      R(j,0,r+1,1){
        if(j==0)
          scanf("%d",&T[i]);
        else
          scanf("%d",&TR[i][j-1]);
      }
    }
    R(i,0,r,1){
      R(j,0,h+1,1){
        if(j==0)
          scanf("%d",&R[i]);
        else
          scanf("%d",&RH[i][j-1]);
      }
    }
    R(i,0,h,1){
      R(j,0,t+1,1){
        if(j==0)
          scanf("%d",&H[i]);
        else
          scanf("%d",&HT[i][j-1]);
      }
    }
    R(i,0,t,1){
      R(j,0,r,1){
        R(k,0,h,1){
          if(!TR[i][j] && !RH[j][k] && !HT[k][i]){
            found=1;
            tmp=T[i]+R[j]+H[k];
            if(tmp<mn){
              mn=tmp;
              anst=i;
              ansr=j;
              ansh=k;
            }
          }
        }
      }
    }
    if(found)
      printf("%d %d %d:%d\n",anst,ansr,ansh,mn);
    else
      puts("Don't get married!");
  }
}
