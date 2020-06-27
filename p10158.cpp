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
    map<string,int> o;
    o["sF"]=1,o["sE"]=2,o["aF"]=3,o["aE"]=4;
    int n;
    cin>>n;
    UnionFind people(2*n);
    string operations;
    cin.ignore();
    int opcode,p1,p2;
    while(getline(cin,operations),operations!="0 0 0"){
        stringstream ss(operations);
        ss>>opcode>>p1>>p2;
        if(opcode==o["sF"]){
            if(people.isSameSet(p1,p2+n)||people.isSameSet(p2,p1+n)){
                cout<< -1 <<endl;
            }
            else{
                people.unionSet(p1,p2);
                people.unionSet(p1+n,p2+n);
            }
        }
        else if(opcode==o["sE"]){
            if(people.isSameSet(p1,p2)||people.isSameSet(p1+n,p2+n)){
                cout<< -1 <<endl;
            }
            else{
                people.unionSet(p1,p2+n);
                people.unionSet(p2,p1+n);
            }
        }
        else if(opcode==o["aF"]){
            if(people.isSameSet(p1,p2)||people.isSameSet(p1+n,p2+n))
                cout<< 1 << endl;
            else{
                cout<< 0 <<endl;
            }
        }
        else if(opcode==o["aE"]){
            if(people.isSameSet(p1,p2+n)||people.isSameSet(p2,p1+n))
                cout<< 1 <<endl;
            else{
                cout<< 0 <<endl;
            }
        }
    }
}
