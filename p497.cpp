#include<bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
void printLIS(int end, int a[], int p[]){
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("%d\n", a[x]);
  for (; !s.empty(); s.pop()) printf("%d\n", s.top());
}
int main(){
  int tc;
  scanf("%d",&tc);
  getchar();
  getchar();
  while(tc--){
    int A[MAX_N],n=0;
    char line[20];
    while(fgets(line,sizeof line,stdin)){
      if(strcmp(line,"\n")==0)
        break;
      A[n]=atoi(line);
      n++;
    }
    int L[n], L_id[n], P[n];
    int lis = 0, lis_end = 0;
    for (int i = 0; i < n; ++i){
      int pos = lower_bound(L, L + lis, A[i]) - L;
      L[pos] = A[i];
      L_id[pos] = i;
      P[i] = pos ? L_id[pos - 1] : -1;
      if (pos + 1 >= lis){
        lis = pos + 1;
        lis_end = i;
      }
    }
    printf("Max hits: %d\n", lis);
    printLIS(lis_end, A, P);
    if(tc)
      putchar('\n');
  }
}
