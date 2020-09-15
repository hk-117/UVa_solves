#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long gcd(long long a,long long b){
  return (b == 0 ? a : gcd(b,a%b));
}
int main(){
  int n,pr=0;
  scanf("%d",&n);
  getchar();
  while(n--){
    char Sa[35],Sb[35];
    long long a,b,res;
    fgets(Sa,sizeof Sa,stdin);
    fgets(Sb,sizeof Sb,stdin);
    Sa[strcspn(Sa,"\n")]='\0';
    Sb[strcspn(Sb,"\n")]='\0';
    a= strtol(Sa,NULL,2);
    b= strtol(Sb,NULL,2);
    res=gcd(a,b);
    printf("Pair #%d: ",++pr);
    if(res>1){
      puts("All you need is love!");
    }
    else{
      puts("Love is not all you need!");
    }
  }
}
