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
  int T,tc=0;
  cin>>T;
  while(T--){
    int Cost=0,u,v,w,N,M,A,airNum=0;
    vector<pair<int,ii>> EdgeList;
    cin>>N>>M>>A;
    for(int i=0;i<M;i++){
      cin>>u>>v>>w;
      EdgeList.push_back(make_pair(w,ii(u,v)));
      EdgeList.push_back(make_pair(w,ii(v,u)));
    }
    UnionFind U(N+1);
    sort(EdgeList.begin(),EdgeList.end());
    for(int i=0;i<EdgeList.size();i++){
      pair<int,ii> front= EdgeList[i];
      if(!U.isSameSet(front.second.first,front.second.second)){
        if(A<=front.first){
          airNum++;
          Cost+=A;
        }
        else{
          Cost+= front.first;
        }
        U.unionSet(front.second.first,front.second.second);
      }
    }
    int extra = U.numDisjointSets()-1;
    printf("Case #%d: %d %d\n",++tc,Cost+(A*extra),airNum+extra);
  }
}
