#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,MAX_N,tmp,tc=0;
  vector<int> A;
  bool nl=false;
  while(scanf("%d",&tmp)==1 && tmp!=-1){
    if(nl) 
      putchar('\n');
    else
      nl=true;
    A.push_back(tmp);
    while(scanf("%d",&tmp)==1 && tmp!=-1){
      A.insert(A.begin(),tmp);
    }
    MAX_N=A.size();
    n=MAX_N;
    int L[MAX_N], L_id[MAX_N], P[MAX_N];
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
    printf("Test #%d:\n",++tc);
    printf("  maximum possible interceptions: %d\n",lis);
    A.clear();
  }
}
