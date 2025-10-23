#include<stdio.h>

const int labels[5] = {10000, 1000, 100, 10, 1};

int determineMax(int b, int others){
  int i;
  if(others < b){
    for(i=0;i<5;i++){
      if(others + labels[i] <= b){
        return labels[i];
      }
    }
  }
  return 0;
}

int main(){
  int n, m;
  while(scanf("%d %d", &n, &m) != EOF){
    int total, dae, i;
    total = 0;
    dae = 0;
    for(i = 1; i<=m; i++){
      int b,tmpDae,others,j;
      scanf("%d", &b);
      scanf("%d", &tmpDae);
      others = 0;
      for(j = 1; j<n ; j++){
        int tmp;
        scanf("%d", &tmp);
        others += tmp;
      }
      if(tmpDae + others <= b){
        dae += tmpDae;
      }
      total += determineMax(b, others);
    }
    printf("%d\n", total - dae);
  }
  return 0;
}
