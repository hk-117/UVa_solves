#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
typedef vector<int> vi;

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
    int tc;
    cin>>tc;
    while(tc--){
        int fship;
        cin>>fship;
        UnionFind mutual(fship*2+1);
        string f1,f2;
        map<string,int> fds;
        int id=1;
        R(i,0,fship,1){
            cin>>f1>>f2;
            if(!fds[f1]){
                fds[f1]=id++;
            }
            if(!fds[f2]){
                fds[f2]=id++;
            }
            mutual.unionSet(fds[f1],fds[f2]);
            cout<< mutual.sizeOfSet(fds[f1]) <<endl;
        }
    }
}
