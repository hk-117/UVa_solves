#include<cstdio>
using namespace std;
int main(){
  int A;
  while(scanf("%d",&A)==1){
    if(A%6==0)
      puts("Y");
    else
      puts("N");
  }
}
