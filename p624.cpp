#include<bits/stdc++.h>
using namespace std;
vector<int> res;
int mx=-1;
void findSum(int N,int sm,vector<int> &L,vector<int> &sub,int idx){
    if(sm>N)
        return;
    if(mx< sm && sm<=N){
        res=sub;
        mx=sm;
    }
    for(int i=idx;i<L.size();i++){
        sub.push_back(L[i]);
        sm+=L[i];
        findSum(N,sm,L,sub,i+1);
        sub.pop_back();
        sm-=L[i];
    }
}
int main(){
    int N,t;
    while(cin>>N>>t){
        vector<int> Lengths(t),sub;
        for(int i=0;i<t;i++){
            cin>>Lengths[i];
        }
        findSum(N,0,Lengths,sub,0);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<"sum:"<<mx<<endl;
        mx=-1;
        res.clear();
    }
}
