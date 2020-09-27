#include<bits/stdc++.h>
#define mx 900000000
using namespace std;
int main(){
  vector<int> HM;
  long long tmp[3];
  for(int i=0;;i++){
    tmp[0]= pow(2,i);
    if(tmp[0]>mx) break;
    for(int j=0;;j++){
      tmp[1]=tmp[0]*pow(3,j);
      if(tmp[1]>mx) break;
      for(int k=0;;k++){
        tmp[2]=tmp[1]*pow(5,k);
        if(tmp[2]>mx) break;
        HM.push_back(tmp[2]);
      }
    }
  }
  sort(HM.begin(),HM.end());
  printf("The 1500'th ugly number is %d.\n",HM[1499]);
}
