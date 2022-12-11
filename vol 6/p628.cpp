#include<bits/stdc++.h>
using namespace std;
vector<string> D;
void matchPwd(string &inp,int idx,string rs,int sz){
    if(sz == inp.size()){
        cout<<rs<<endl;
        return;
    }
    for(int i=idx;i<inp.size();i++){
        if(inp[i]=='#'){
            for(int j=0;j<D.size();j++){
                string tmp=rs;
                rs+= D[j];
                matchPwd(inp,i+1,rs,sz+1);
                rs=tmp;
            }
        }
        else{
            for(int j=0;j<=9;j++){
                string tmp=rs;
                rs+= to_string(j);
                matchPwd(inp,i+1,rs,sz+1);
                rs=tmp;
            }
        }
    }
}
int main(){
    int n,m;
    while(cin>>n){
        D.clear();
        string inp,rs;
        for(int i=0;i<n;i++){
            cin>>inp;
            D.push_back(inp);
        }
        cin>>m;
        cout<<"--"<<endl;
        for(int i=1;i<=m;i++){
            cin>>inp;
            matchPwd(inp,0,rs,0);
        }
    }
}
