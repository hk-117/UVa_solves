#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
  return (b==0? a:(gcd(b,a%b)));
}
int main(){
  int j,k,tc=0;
  long long Num,Deno,g,a,b;
  char NM[15];
  while(scanf("%d",&j)==1 && j!=-1){
    char BD[15];
    scanf("%s",NM);
    k= strlen(NM+2)-j;
    if(j==0){
      Num= atol(NM+2);
      Deno= pow(10,k);
    }
    else{
      a=0;
      b=0;
      a= atol(NM+2);
      if(k>0){
        strncpy(BD,NM+2,k);
        BD[k]='\0';
        b= atol(BD);
      }
      Num=a-b;
      Deno= pow(10,k+j)-pow(10,k);
    }
    g= gcd(Num,Deno);
    printf("Case %d: %lld/%lld\n",++tc,Num/g,Deno/g);
  }
}
