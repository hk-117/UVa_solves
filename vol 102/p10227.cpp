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
    cin.ignore();
    while(tc--){
        int p,t;
        cin>>p>>t;
        UnionFind opinions(p);
        set<int> people[p];
        string inp;
        int pi,ti;
        cin.ignore();
        while(getline(cin,inp),inp.size()){
            stringstream ss(inp);
            ss>>pi>>ti;
            people[pi-1].insert(ti);
        }
        R(i,0,p-1,1){
            R(j,i+1,p,1){
                if( people[i]==people[j] ){
                    opinions.unionSet(i,j);
                }
            }
        }
        cout<< opinions.numDisjointSets() <<endl;
        if(tc)
            cout<<endl;
    }
}
