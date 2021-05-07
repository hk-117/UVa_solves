#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,bool> E;
    vector<string> W,R;
    string inp,a,b;
    while(cin>>inp){
        W.push_back(inp);
        E[inp]=true;
    }
    for(int i=0;i<W.size();i++){
        for(int j=0;j<W[i].size();j++){
            a.assign(W[i],0,j+1);
            b.assign(W[i],j+1,W[i].size()-j+1);
            if(E.find(a)!=E.end() && E.find(b)!=E.end()){
                R.push_back(W[i]);
                break;
            }
        }
    }
    sort(R.begin(),R.end());
    for(int i=0;i<R.size();i++){
        cout<<R[i]<<"\n";
    }
}
