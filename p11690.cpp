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
    int N;
    cin>>N;
    while(N--){
        int n,m;
        cin>>n>>m;
        UnionFind fgroup(n);
        map<int,set<int>> groups;
        int debts[n];
        R(i,0,n,1){
            cin>>debts[i];
        }
        int x,y,g;
        R(i,0,m,1){
            cin>>x>>y;
            fgroup.unionSet(x,y);
        }
        R(i,0,n,1){
            g=fgroup.findSet(i);
            groups[g].insert(i);
        }
        bool possible=true;
        for(auto it=groups.begin();it!=groups.end();it++){
            int total=0;
            for(auto st= it->second.begin();st!= it->second.end();st++){
                total+= debts[*st];
            }
            if(total != 0){
                possible=false;
                break;
            }
        }
        if(possible)
            cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
}
