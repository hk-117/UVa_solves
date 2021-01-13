#include <stdio.h>
#include <string.h>
char str[30], ans[30];
int len,N,Positions[30];
void findIndexStr(){
  int i,j;
  N--;
  for(i=len;i>0;i--){
    Positions[i-1]=N%i;
    N=N/i;
  }
  for(i = 0; i <len; i++) {
    for(j=len-1;j>Positions[i];j--){
      ans[j]=ans[j-1];
    }
    ans[Positions[i]]=str[i];
  }
  ans[len]='\0';
  puts(ans);
}
int main() {
  int TC;
  scanf("%d",&TC);
  while(TC--){
    scanf("%s",str);
    scanf("%d",&N);
    len = strlen(str);
    findIndexStr();
  }
  return 0;
}
