#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
class UnionFind{
  private:
    vi p,rank,setSize;
    int numSets;
  public:
    UnionFind(int N){
      setSize.assign(N,1);
      rank.assign(N,0);
      p.assign(N,0);
      numSets=N;
      for(int i=0;i<N;i++){
          p[i]=i;
      }
    }
    int findSet(int i){
      return (p[i]==i)? i: (p[i]=findSet(p[i]));
    }
    bool isSameSet(int i,int j){
      return findSet(i)==findSet(j);
    }
    void unionSet(int i,int j){
      if(!isSameSet(i,j)){
        numSets--;
        int x=findSet(i),y=findSet(j);
        if(rank[x]>rank[y]){
          p[y]=x;
          setSize[x]+=setSize[y];
        }
        else{
          p[x]=y;
          setSize[y]+=setSize[x];
          if(rank[x]==rank[y])
            rank[y]++;
        }
      }
    }
    int numDisjointSets(){
      return numSets;
    }
    int sizeOfSet(int i){
      return setSize[findSet(i)];
    }
};
struct POS{
  double x,y;
};
int main(){
  int T;
  cin>>T;
  while(T--){
    int N;
    cin>>N;
    vector<POS> poses(N);
    vector<pair<double,ii>> EdgeList;
    for(int i=0;i<N;i++){
      cin>> poses[i].x >> poses[i].y;
    }
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        double xx=fabs(poses[i].x-poses[j].x);
        double yy=fabs(poses[i].y-poses[j].y);
        double dist= sqrt(xx*xx + yy*yy);
        EdgeList.push_back(make_pair(dist,ii(i,j)));
      }
    }
    sort(EdgeList.begin(),EdgeList.end());
    double cost=0.0;
    UnionFind U(N);
    for(int i=0;i<EdgeList.size();i++){
      pair<double,ii> front= EdgeList[i];
      if(!U.isSameSet(front.second.first,front.second.second)){
        cost+= front.first;
        U.unionSet(front.second.first,front.second.second);
      }
    }
    printf("%.2lf\n",cost);
    if(T)
      puts("");
  }
}
