#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    while(cin>>n>>m){
        map<int,vector<int>> occur;
        long long dm;
        for(long long i=1;i<=n;i++){
            cin>>dm;
            occur[dm].push_back(i);
        }
        long long k,v;
        for(long long i=1;i<=m;i++){
            cin>>k>>v;
            if(occur[v].size()<k)
                cout<<0<<endl;
            else
                cout<<occur[v][k-1]<<endl;
        }
    }
}
