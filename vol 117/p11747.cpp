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
  int N,M;
  while(scanf("%d %d",&N,&M)==2 && (N||M)){
    int u,v,w;
    vector<pair<int,ii>> EdgeList;
    for(int i=0;i<M;i++){
      scanf("%d %d %d",&u,&v,&w);
      EdgeList.push_back(make_pair(w,ii(u,v)));
      EdgeList.push_back(make_pair(w,ii(v,u)));
    }
    UnionFind U(N);
    sort(EdgeList.begin(),EdgeList.end());
    set<int> H;
    map<int,bool> used;
    for(int i=0;i<EdgeList.size();i++){
      pair<int,ii> front= EdgeList[i];
      if(!U.isSameSet(front.second.first,front.second.second)){
        U.unionSet(front.second.first,front.second.second);
        used[front.first]=true;
      }
      else{
        if(!used[front.first])
          H.insert(front.first);
      }
    }
    if(!H.size())
      puts("forest");
    else{
      bool sp=false;
      for(auto it=H.begin();it!=H.end();it++){
        if(!sp) sp=true;
        else printf(" ");
        printf("%d",*it);
      }
      printf("\n");
    }
  }
}
