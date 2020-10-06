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
  int T;
  cin>>T;
  while(T--){
    int Cost=0,M,N,u,v,w,cnt=1;
    string un,vn;
    vector<pair<int,ii>> EdgeList;
    map<string,int> NmMap;
    cin>>M>>N;
    for(int i=0;i<N;i++){
      cin>>un>>vn>>w;
      if(NmMap[un]==0){
        u=cnt;
        NmMap[un]=cnt;
        cnt++;
      }
      else{
        u=NmMap[un];
      }
      if(NmMap[vn]==0){
        v=cnt;
        NmMap[vn]=cnt;
        cnt++;
      }
      else{
        v=NmMap[vn];
      }
      EdgeList.push_back(make_pair(w,ii(u,v)));
      EdgeList.push_back(make_pair(w,ii(v,u)));
    }
    UnionFind U(M+1);
    sort(EdgeList.begin(),EdgeList.end());
    for(int i=0;i<EdgeList.size();i++){
      pair<double,ii> front= EdgeList[i];
      if(!U.isSameSet(front.second.first,front.second.second)){
        Cost+= front.first;
        U.unionSet(front.second.first,front.second.second);
      }
    }
    printf("%d\n",Cost);
    if(T)
      puts("");
  }
}
