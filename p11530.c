#include<stdio.h>
#include<string.h>
int presCount[150];
void makePresCount(){
  int i,cnt=1;
  presCount[' ']=1;
  for(i='a';i<'z';i++){
    presCount[i]=cnt;
    cnt++;
    if(cnt>3 && i!='s'-1)
      cnt=1;
  }
  presCount['z']=4;
}
int main(){
  int T,tc=0,len,i,res;
  char line[105];
  scanf("%d",&T);
  getchar();
  makePresCount();
  while(T--){
    fgets(line,sizeof line,stdin);
    len=strcspn(line,"\n\r");
    line[len]='\0';
    res=0;
    for(i=0;i<len;i++){
      res+=presCount[line[i]];
    }
    printf("Case #%d: %d\n",++tc,res);
  }
}
