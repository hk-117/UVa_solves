#include<stdio.h>
#include<string.h>
#include<limits.h>
char IdxStr[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int IdxPointer[123],PSize[52];
int PStr[52][100000];

void makeIdxPointer(){
  int i;
  for(i=0;i<53;i++){
    IdxPointer[IdxStr[i]]=i;
  }
}

int find(int State,int key){
  int mid,start=0,end=PSize[State]-1,val;
  while(start<=end){
    mid=(start+end)/2;
    if(PStr[State][mid]<key){
      start=mid+1;
    }
    else{
      end= mid-1;
      val=PStr[State][mid];
    }
  }
  if(val<key)
    return -1;
  return val;
}

int main(){
  int len,i,j,Q,Qsize;
  char Line[1000005],Qline[105];
  scanf("%s",Line);
  len=strlen(Line);
  makeIdxPointer();
  for(i=0;i<len;i++){
    int pos=IdxPointer[Line[i]];
    PStr[pos][PSize[pos]]=i;
    PSize[pos]++;
  }
  getchar();
  scanf("%d",&Q);
  getchar();
  while(Q--){
    int nextPos,prevPos=0,startPos=INT_MAX,endPos=INT_MIN;
    scanf("%s",Qline);
    Qsize=strlen(Qline);
    for(i=0;i<Qsize;i++){
      nextPos=find(IdxPointer[Qline[i]],prevPos);
      if(nextPos==-1){
        break;
      }
      startPos=startPos<nextPos ? startPos:nextPos;
      endPos=endPos>nextPos? endPos:nextPos;
      prevPos=nextPos+1;
    }
    if(nextPos==-1){
      printf("Not matched\n");
    }
    else{
      printf("Matched %d %d\n",startPos,endPos);
    }
  }
}
