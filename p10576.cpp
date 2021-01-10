#include<cstdio>
#include<climits>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
typedef struct{
  int status;
  long long int sum;
} Pair;
long long int s,d,Sum;
Pair res;
Pair validateArr(long long int *arr){
  int i,j;
  long long int stmp;
  Pair tmp;
  tmp.status=1;
  for(i=4;i<12;i++){
    stmp=0;
    for(j=i-4;j<=i;j++){
      stmp+=arr[j];
    }
    if(stmp>=0){
      tmp.status=0;
      break;
    }
  }
  if(tmp.status){
    tmp.sum=0;
    for(i=0;i<12;i++){
      tmp.sum+=arr[i];
    }
  }
  return tmp;
}
void genCombination(long long int *arr,int cnt){
  if(cnt==12){
    res=validateArr(arr);
    if(res.status){
      Sum=max(Sum,res.sum);
    }
  }
  else{
    arr[cnt]=s;
    genCombination(arr,++cnt);
    --cnt;
    arr[cnt]=d;
    genCombination(arr,++cnt);
  }
}
int main(){
  long long int arr[12];
  while(scanf("%lld %lld",&s,&d)==2){
    d=-d;
    Sum=INT_MIN;
    genCombination(arr,0);
    if(Sum<0)
      puts("Deficit");
    else
      printf("%lld\n",Sum);
  }
}
