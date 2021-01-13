#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char Papers[15][35],Ans[15][35];
int N,start,end,target;
void makeRange(char *L,int len){
  int i;
  if(L[0]=='*'){
    start=1;
    end=N;
  }
  else{
    char *p;
    int flag=0;
    p=strtok(L," ");
    while(p){
      if(!flag){
        start=atoi(p);
        flag++;
      }
      else{
        end=atoi(p);
        flag++;
      }
      p=strtok(NULL," ");
    }
    if(flag==1){
      end=start;
    }
  }
}
void makeSubSet(int len,int idx){
  if(len>N+1 || idx>N)
    return;
  if(len==target){
    int i;
    printf("%s",Ans[0]);
    for(i=1;i<len;i++){
      printf(", %s",Ans[i]);
    }
    printf("\n");
  }
  else{
    strcpy(Ans[len],Papers[idx]);
    makeSubSet(len+1,idx+1);
    makeSubSet(len,idx+1);
  }
}
int main(){
  int M,Rlen,len,i;
  char line[35],Range[35];
  scanf("%d",&M);
  getchar();
  getchar();
  while(M--){
    fgets(Range,sizeof Range,stdin);
    Rlen=strcspn(Range,"\n");
    Range[Rlen]='\0';
    N=0;
    while(fgets(line,sizeof line,stdin)){
      len=strcspn(line,"\n");
      if(!len)
        break;
      line[len]='\0';
      strcpy(Papers[N++],line);
    }
    makeRange(Range,Rlen);
    for(target=start;target<=end;target++){
      printf("Size %d\n",target);
      makeSubSet(0,0);
      printf("\n");
    }
    if(M)
      printf("\n");
  }
}
