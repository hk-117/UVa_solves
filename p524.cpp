#include<bits/stdc++.h>
using namespace std;
int N;
bitset<20> Taken;
vector<int> Ring;
bool isPrime(int N){
  for(int i=2;i*i<=N;i++){
    if(N%i==0)
      return false;
  }
  return true;
}
void getSoln(int i){
  if(i+1==N){
    printf("1");
    for(int j=1;j<N;j++){
      printf(" %d",Ring[j]);
    }
    puts("");
  }
  else{
    for(int j=2;j<=N;j++){
      if(Taken[j])
        continue;
      if(i+1==N-1){
        if(isPrime(Ring[i]+j) && isPrime(Ring[0]+j)){
          Ring.push_back(j);
          Taken[j]=true;
          getSoln(i+1);
          Taken[j]=false;
          Ring.erase(Ring.end()-1);
        }
      }
      else{
        if(isPrime(Ring[i]+j)){
          Ring.push_back(j);
          Taken[j]=true;
          getSoln(i+1);
          Taken[j]=false;
          Ring.erase(Ring.end()-1);
        }
      }
    }
  }
}
int main(){
  int i,Cs=0;
  Ring.push_back(1);
  while(scanf("%d",&N)==1){
    if(Cs){
      puts("");
      Cs++;
    }
    else{
      Cs++;
    }
    printf("Case %d:\n",Cs);
    getSoln(0);
    Ring.clear();
    Ring.push_back(1);
  }
}
