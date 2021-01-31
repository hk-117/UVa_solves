#include<stdio.h>
#include<stdlib.h>
#define MX 1000
long long int Ns[MX],lim=2147483648,Size;
void makeNums(){
  long long int i,j,prod1=1,prod2=1,res=1;
  Ns[Size++]=1;
  for(i=1;i<=32;i++){
    prod2=1;
    res=1;
    for(j=1;res<=lim;j++){
      res=prod1*prod2;
      Ns[Size++]=res;
      prod2*=3;
    }
    prod1*=2;
  }
}
int cmp(const void *a,const void *b){
  long long int *na=(long long int*) a;
  long long int *nb=(long long int*) b;
  if((*na-*nb)<0)
    return -1;
  else
    return 1;
}
long long int lowerBound(int start,int end,long long key){
  int mid;
  if(key<=Ns[0]) return Ns[0];
  while(start<=end){
    mid=start+ (end-start)/2;
    if(Ns[mid]>=key && Ns[mid-1]<key)
      return Ns[mid];
    if(Ns[mid]<key)
      start=mid+1;
    else
      end=mid-1;
  }
}
int main(){
  long long int m;
  makeNums();
  qsort(Ns,Size,sizeof Ns[0],cmp);
  while(scanf("%lld",&m)==1 && m){
    printf("%lld\n",lowerBound(0,Size-1,m));
  }
  return 0;
}
