#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int number,capacity;
} Table;

typedef struct{
  int number,members;
} Team;

Table table[55];
Team team[75];
int AnswerTable[75][55];
int M,N;

int tableCmp(const void *a,const void *b){
  Table *at= (Table*) a;
  Table *bt= (Table*) b;
  return (at->capacity - bt->capacity);
}

int teamCmp(const void *a,const void *b){
  Team *at= (Team*) a;
  Team *bt= (Team*) b;
  return (bt->members - at->members);
}

int main(){
  int i,j;
  while(scanf("%d %d",&M,&N)==2 && (M||N)){
    int possible=1;
    for(i=0;i<M;i++){
      scanf("%d",&team[i].members);
      team[i].number=i+1;
      AnswerTable[i][0]=0;
    }
    for(j=0;j<N;j++){
      scanf("%d",&table[j].capacity);
      table[j].number=j+1;
    }
    qsort(table,N,sizeof table[0],tableCmp);
    qsort(team,M,sizeof team[0],teamCmp);
    for(i=0;i<M && possible;i++){
      j=0;
      while(j<N && possible && team[i].members){
        if(table[j].capacity==0){
          j++;
          continue;
        }
        else{
          int tmNo;
          table[j].capacity--;
          team[i].members--;
          tmNo=team[i].number;
          AnswerTable[tmNo-1][++AnswerTable[tmNo-1][0]]=table[j].number;
          j++;
        }
      }
      if(team[i].members)
        possible=0;
    }
    if(!possible){
      printf("0\n");
    }
    else{
      printf("1\n");
      for(i=0;i<M;i++){
        printf("%d",AnswerTable[i][1]);
        for(j=2;j<=AnswerTable[i][0];j++){
          printf(" %d",AnswerTable[i][j]);
        }
        printf("\n");
      }
    }
  }
}
