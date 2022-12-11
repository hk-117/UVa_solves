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
char CT[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  int T,tc=0;
  cin>>T;
  while(T--){
    int N,u,v,w;
    string wrd;
    vector<pair<int,ii>> EdgeList;
    cin>>N;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        cin>>wrd;
        if(i!=j){
          w= atoi(wrd.c_str());
          if(w!=0){
            EdgeList.push_back(make_pair(w,ii(i,j)));
            EdgeList.push_back(make_pair(w,ii(j,i)));
          }
        }
      }
    }
    UnionFind U(N);
    sort(EdgeList.begin(),EdgeList.end());
    printf("Case %d:\n",++tc);
    for(int i=0;i<EdgeList.size();i++){
      pair<int,ii> front= EdgeList[i];
      if(!U.isSameSet(front.second.first,front.second.second)){
        printf("%c-%c %d\n",CT[front.second.first],CT[front.second.second],front.first);
        U.unionSet(front.second.first,front.second.second);
      }
    }
  }
}
