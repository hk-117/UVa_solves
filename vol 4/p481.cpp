#include<bits/stdc++.h>
#define MAX_N 100000
using namespace std;
void printLIS(int end, int a[], int p[]) {
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(a[x]);
  printf("%d\n", a[x]);
  for (; !s.empty(); s.pop()) printf("%d\n", s.top());
}
int main() {
  int n=0, A[MAX_N],tmp;
  while(scanf("%d",&tmp)==1){
    A[n]=tmp;
    n++;
  }
  int L[MAX_N], L_id[MAX_N], P[MAX_N];
  int lis = 0, lis_end = 0;
  for (int i = 0; i < n; ++i) {
    int pos = lower_bound(L, L + lis, A[i]) - L;
    L[pos] = A[i];
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if (pos + 1 >= lis) {
      lis = pos + 1;
      lis_end = i;
    }
  }
  printf("%d\n-\n", lis);
  printLIS(lis_end, A, P);

}
