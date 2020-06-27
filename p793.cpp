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
            setSize.assign(N+1,1);
            rank.assign(N+1,0);
            p.assign(N+1,0);
            numSets=N;
            for(int i=0;i<=N;i++){
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
    int cs;
    cin>>cs;
    cin.ignore();
    while(cs--){
        int N,success=0,unsuccess=0,c1,c2;
        char command;
        cin>>N;
        UnionFind network(N);
        string inp;
        cin.ignore();
        while(getline(cin,inp),inp.size()){
            stringstream ss(inp);
            ss>>command>>c1>>c2;
            if(command=='c'){
                network.unionSet(c1,c2);
            }
            else{
                if(network.isSameSet(c1,c2)){
                    success++;
                }
                else
                    unsuccess++;
            }
        }
        cout<<success<<","<<unsuccess<<endl;
        if(cs)
            cout<<endl;
    }
}
