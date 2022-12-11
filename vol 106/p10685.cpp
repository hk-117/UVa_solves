#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
typedef vector<int> vi;

class UnionFind{
    private:
        vi p,rank,setSize;
        int numSets;
    public:
        int maxi=1;
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
                    maxi=max(maxi,setSize[x]);
                }
                else{
                    p[x]=y;
                    setSize[y]+=setSize[x];
                    maxi=max(maxi,setSize[y]);
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
    int c,m;
    while(cin>>c>>m,c||m){
        int a,b;
        map<string,int> animals;
        UnionFind chain(c);
        string anime,khaddo,khadok;
        R(i,0,c,1){
            cin>>anime;
            animals[anime]=i;
        }
        R(i,1,m+1,1){
            cin>>khaddo>>khadok;
            chain.unionSet(animals[khadok],animals[khaddo]);
        }
        cin.ignore();
        cout<< chain.maxi <<endl;
    }
}
