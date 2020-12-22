#include<bits/stdc++.h>
using namespace std;
struct Elep{
  int id,w,iq;
  bool operator<(Elep a){
    if(iq==a.iq)
      return w>a.w;
    return iq>a.iq;
  }
};
vector<Elep> A;
void printLIS(int end, int p[]){
  int x = end;
  stack<int> s;
  for (; p[x] >= 0; x = p[x]) s.push(A[x].id);
  printf("%d\n", A[x].id);
  for (; !s.empty(); s.pop()) printf("%d\n", s.top());
}
int main(){
  int n=0,tmp1,tmp2;
  Elep a;
  while(scanf("%d %d",&tmp1,&tmp2)==2){
    a.id=n+1;
    a.w=tmp1;
    a.iq=tmp2;
    A.push_back(a);
    n++;
  }
  sort(A.begin(),A.end());
  n=A.size();
  int L[n], L_id[n], P[n];
  int lis = 0, lis_end = 0;
  for (int i = 0; i < n; ++i){
    int pos = lower_bound(L, L + lis, A[i].w) - L;
    L[pos] = A[i].w;
    L_id[pos] = i;
    P[i] = pos ? L_id[pos - 1] : -1;
    if (pos + 1 > lis){
      lis = pos + 1;
      lis_end = i;
    }
  }
  printf("%d\n", lis);
  printLIS(lis_end, P);
}
