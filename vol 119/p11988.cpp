#include<bits/stdc++.h>
using namespace std;

int main(){
    string inp;
    while(cin>>inp){
        list<char> broken;
        auto it=broken.begin();
        for(int i=0,sz=inp.size();i<sz;i++){
            if(inp[i]=='[')
                it=broken.begin();
            else if(inp[i]==']')
                it=broken.end();
            else
                broken.insert(it,inp[i]);
        }
        for(auto it=broken.begin();it!=broken.end();it++)
            cout<< *it;
        cout<<endl;
    }
}
