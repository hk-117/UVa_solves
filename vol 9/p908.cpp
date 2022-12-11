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
int main(){
  int N,K,M;
  bool nl=false;
  while(scanf("%d",&N)==1){
    if(!nl) nl=true;
    else puts("");
    int prevCost=0,newCost=0,u,v,w;
    vector<pair<int,ii>> EdgeList;
    for(int i=0;i<N-1;i++){
      scanf("%d %d %d",&u,&v,&w);
      prevCost+=w;
      EdgeList.push_back(make_pair(w,ii(u,v)));
      EdgeList.push_back(make_pair(w,ii(v,u)));
    }
    UnionFind U(N+1);
    scanf("%d",&K);
    for(int k=1;k<=K;k++){
      scanf("%d %d %d",&u,&v,&w);
      EdgeList.push_back(make_pair(w,ii(u,v)));
      EdgeList.push_back(make_pair(w,ii(v,u)));
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
      scanf("%d %d %d",&u,&v,&w);
    }
    sort(EdgeList.begin(),EdgeList.end());
    for(int i=0;i<EdgeList.size();i++){
      pair<double,ii> front= EdgeList[i];
      if(!U.isSameSet(front.second.first,front.second.second)){
        newCost+= front.first;
        U.unionSet(front.second.first,front.second.second);
      }
    }
    printf("%d\n%d\n",prevCost,newCost);
  }
}
