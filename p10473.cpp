#include<bits/stdc++.h>
using namespace std;
int main(){
  char num[50];
  long long N;
  while(scanf("%s",num)==1 && (strchr(num,'-')==NULL)){
    if(strstr(num,"0x")!=NULL){
      N= strtol(num,NULL,16);
      printf("%lld\n",N);
    }
    else{
      N=strtol(num,NULL,0);
      printf("0x%llX\n",N);
    }
  }
}
