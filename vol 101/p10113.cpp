#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pi;
typedef pair<int,pi> ppi;
vector<ppi> G[65];
bool visited[65],found;
int m,n,fnl,strt;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void dfs(int u){
  visited[u]=true;
  if(u==fnl){
    found=true;
    return;
  }
  int g,ma=m,na=n;
  for(int j=0;j<(int) G[u].size() && !found;j++){
    ppi v= G[u][j];
    if(!visited[v.first]){
      if(u==strt){
        m=1;
        n=1;
      }
      m*= v.second.first;
      n*= v.second.second;
      g = gcd(m,n);
      m= m/g;
      n= n/g;
      dfs(v.first);
      if(!found) {
        m=ma;
        n=na;
      }
    }
  }
}

int main(){
  char op,eql;
  string fst,lst;
  int a,b,cnt=0;
  map<string,int> Mpr;
  map<int,string> IMpr;
  while(cin>>op,op!='.'){
    if(op=='!'){
      cin>>a>>fst>>eql>>b>>lst;
      if(Mpr.find(fst)==Mpr.end()){
        cnt++;
        Mpr[fst]=cnt;
        IMpr[cnt]=fst;
      }
      if(Mpr.find(lst)==Mpr.end()){
        cnt++;
        Mpr[lst]=cnt;
        IMpr[cnt]=lst;
      }
      G[Mpr[fst]].pb(mp(Mpr[lst],mp(a,b)));
      G[Mpr[lst]].pb(mp(Mpr[fst],mp(b,a)));
    }
    else{
      cin>>fst>>eql>>lst;
      strt=Mpr[fst];
      fnl=Mpr[lst];
      memset(visited,false,sizeof visited);
      found=false;
      m=1;
      n=1;
      dfs(strt);
      if(!found){
        cout<< "? " << fst <<" = ? "<< lst <<endl;
      }
      else{
        cout<< m <<" "<< fst <<" = "<< n <<" "<<lst <<endl;
      }
    }
  }
}
