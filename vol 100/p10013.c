#include<stdio.h>
#include<string.h>
#define mx 10000050
int sm[mx],nm[mx];
int main(){
  int n,m;
  scanf("%d",&n);
  while(n--){
    int i,j,sum,carry=0,a,b;
    scanf("%d",&m);
    for(i=0;i<m;i++){
      scanf("%d %d",&a,&b);
      sm[i]=a;
      nm[i]=b;
    }
    for(i=m-1;i>=0;i--){
      sum=(sm[i]+nm[i]+carry)%10;
      carry= (sm[i]+nm[i]+carry)/10;
      sm[i]=sum;
    }
    if(carry>0) printf("%d",carry);
    for(i=0;i<m;i++)
      printf("%d",sm[i]);
    putchar('\n');
    if(n)
      putchar('\n');
  }
}
