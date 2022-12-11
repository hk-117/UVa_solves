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
    char wrd[30];
    vector<string> Ot;
    map<string,bool> Mpr;
    R(i,0,N,1){
      R(j,0,N,1){
        R(k,0,N,1){
          if(i==j && j==k)
            continue;
          if((Mat[i][j] && Mat[j][k] && Mat[k][i]) || ((Mat[i][j]==0 && Mat[j][i]==0)&&(Mat[j][k]==0 && Mat[k][j]==0)&&(Mat[k][i]==0 && Mat[i][k]==0))){
            if((i<j && j<k) || (i>j && j>k)){
              sprintf(wrd,"%d %d %d",i+1,j+1,k+1);
              string w(wrd);
              sprintf(wrd,"%d %d %d",k+1,j+1,i+1);
              string wo(wrd);
              if(!Mpr[w] && !Mpr[wo]){
                Ot.push_back(w);
                Mpr[w]=true;
                Mpr[wo]=true;
                total++;
              }
            }
          }
        }
      }
    }
    printf("%d\n",total);
    R(i,0,total,1)
      cout<<Ot[i]<<endl;
  }
}
