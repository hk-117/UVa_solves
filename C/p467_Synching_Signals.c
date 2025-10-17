#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int minElement(int arr[], int size){
  int i;
  int min = arr[0];
  for(i=1;i<size;i++){
    if(arr[i]<min){
      min = arr[i];
    }
  }
  return min;
}

void initStatus(int *stats, int size){
  int i;
  for(i=0;i<size;i++){
    stats[i] = 0;
  }
}

int checkGreens(int time, int *sigs, int *stats, int size){
  int i;
  for(i=0;i<size;i++){
    if((time % (sigs[i]*2)) >= (sigs[i]-5)){
      stats[i] = 0;
    } else {
      stats[i] = 1;
    }
  }
  for(i=0;i<size;i++){
    if(stats[i]==0){
      return 0;
    }
  }
  return 1;
}

int main(){
  char input[105];
  int length,sigs[10],testcase,stats[10],minimum;
  testcase = 0;
  while(fgets(input,105,stdin)!=NULL){
    char *p;
    length = 0;
    input[strcspn(input, "\n")] = 0;
    p = strtok(input," ");
    while(p!=NULL){
      sigs[length++] = atoi(p);
      p = strtok(NULL," ");
    }
    minimum = minElement(sigs,length);
    minimum *= 2;
    initStatus(stats, length);
    while(!checkGreens(minimum, sigs, stats, length) && minimum<=3600){
      minimum++;
    }
    if(minimum == 3601){
      printf("Set %d is unable to synch after one hour.\n",++testcase);
    }else{
      printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n",++testcase,minimum/60,minimum%60);
    }
  }
  return 0;
}
