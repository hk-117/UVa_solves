#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
  int tA,tB;
} Pair;

int t,preal,s,taken[20],ans[20];
char Topics[20][20];
Pair Map[250];
void makeAllCap(char *str){
  int i;
  for(i=0;str[i]!='\0';i++)
    str[i]=toupper(str[i]);
}
int cmp(const void *a,const void *b){
  char *sa= (char*) a;
  char *sb= (char*) b;
  int la,lb;
  la=strlen(sa);
  lb=strlen(sb);
  if(la==lb)
    return strcmp(sa,sb);
  else
    return lb-la;
}
int findPos(char *str){
  int i;
  for(i=0;i<t;i++){
    if(!strcmp(Topics[i],str))
      return i;
  }
}
int isExists(Pair tmp){
  int i;
  for(i=0;i<preal;i++){
    if(tmp.tA==Map[i].tA && tmp.tB==Map[i].tB)
      return 1;
  }
  return 0;
}
int isForbidden(int pos){
  int i;
  for(i=0;i<preal;i++){
    if(Map[i].tA==pos && taken[Map[i].tB]==1)
      return 1;
  }
  return 0;
}
void findGroups(int pos,int len){
  int i;
  Pair chk;
  if(len==s){
    printf("%s",Topics[ans[0]]);
    for(i=1;i<len;i++)
      printf(" %s",Topics[ans[i]]);
    printf("\n");
    return;
  }
  if(pos>=t || len>=s)
    return;
  if(isForbidden(pos)){
    findGroups(pos+1,len);
  }
  else{
    ans[len]=pos;
    taken[pos]=1;
    findGroups(pos+1,len+1);
    taken[pos]=0;
    findGroups(pos+1,len);
  }
}
int main(){
  int T,tc=0,p;
  scanf("%d",&T);
  while(T--){
    int i,j;
    Pair tmp;
    char cA[20],cB[20];
    tc++;
    scanf("%d %d %d",&t,&p,&s);
    getchar();
    for(i=0;i<t;i++){
      scanf("%s",Topics[i]);
      makeAllCap(Topics[i]);
    }
    qsort(Topics,t,sizeof Topics[0],cmp);
    preal=0;
    for(i=0;i<p;i++){
      scanf("%s %s",cA,cB);
      makeAllCap(cA);
      makeAllCap(cB);
      tmp.tA=findPos(cA);
      tmp.tB=findPos(cB);
      if(!isExists(tmp)){
        Map[preal]=tmp;
        preal++;
        Map[preal].tA=tmp.tB;
        Map[preal].tB=tmp.tA;
        preal++;
      }
    }
    memset(taken,0,sizeof taken);
    taken[0]=1;
    printf("Set %d:\n",tc);
    findGroups(0,0);
    printf("\n");
  }
}
