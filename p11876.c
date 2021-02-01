#include<stdio.h>
#define MAX_P 1010
#define MAX_N 1000005
typedef long long ll;
short int bs[MAX_P];
int Primes[MAX_P/2],PSize;
ll Seq[65000],SSize;
void sieve(ll upb){
  ll sieve_size=upb+1,i,j;
  bs[0]=1;
  bs[1]=1;
  for(i=2;i<=sieve_size;i++){
    if(!bs[i]){
      for(j=i*i;j<=sieve_size;j+=i){
        bs[j]=1;
      }
      Primes[PSize++]=i;
    }
  }
}
ll numDiv(ll N){
  if(N==0||N==1) return N;
  ll PF_idx=0,PF=Primes[PF_idx],ans=1;
  while(PF*PF <= N){
    int power=0;
    while(N%PF==0){
      N/=PF;
      power++;
    }
    ans*=(power+1);
    PF=Primes[++PF_idx];
  }
  if(N!=1) ans*=2;
  return ans;
}
int lowerBound(int start,int end,int key){
  int mid;
  while(start<end){
    mid=start+(end-start)/2;
    if(key<=Seq[mid]){
      end=mid;
    }
    else{
      start=mid+1;
    }
  }
  return start;
}
int upperBound(int start,int end,int key){
  int mid;
  while(start<end){
    mid=start+(end-start)/2;
    if(key>= Seq[mid])
      start=mid+1;
    else
      end=mid;
  }
  return start;
}
int main(){
  int A,B,T,tc=0;
  sieve(MAX_P);
  Seq[SSize]=1;
  while(Seq[SSize]<MAX_N){
    ++SSize;
    Seq[SSize]= Seq[SSize-1]+numDiv(Seq[SSize-1]);
  }
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&A,&B);
    printf("Case %d: %d\n",++tc,upperBound(0,SSize,B)-lowerBound(0,SSize,A));
  }
}
