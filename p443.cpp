#include<bits/stdc++.h>
#define mx 2000000000
using namespace std;
int main(){
  vector<int> HM;
  long long tmp[4];
  for(int i=0;;i++){
    tmp[0]= pow(2,i);
    if(tmp[0]>mx) break;
    for(int j=0;;j++){
      tmp[1]=tmp[0]*pow(3,j);
      if(tmp[1]>mx) break;
      for(int k=0;;k++){
        tmp[2]=tmp[1]*pow(5,k);
        if(tmp[2]>mx) break;
        for(int l=0;;l++){
          tmp[3]=tmp[2]*pow(7,l);
          if(tmp[3]>mx) break;
          HM.push_back(tmp[3]);
        }
      }
    }
  }
  sort(HM.begin(),HM.end());
  int N;
  while(scanf("%d",&N)==1 && N){
    if(N%10 == 1 && N%100!=11){
      printf("The %dst humble number is %d.\n",N,HM[N-1]);
    }
    else if(N%10 ==2 && N%100 !=12){
      printf("The %dnd humble number is %d.\n",N,HM[N-1]);
    }
    else if(N%10 == 3 && N%100 != 13){
      printf("The %drd humble number is %d.\n",N,HM[N-1]);
    }
    else{
      printf("The %dth humble number is %d.\n",N,HM[N-1]);
    }
  }
}
