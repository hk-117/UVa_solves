#include<bits/stdc++.h>
using namespace std;

int main(){
    string inp;
    while(cin>>inp,inp!="END"){
        int cnt=1;
        while(inp!="1"){
            inp= to_string(inp.size());
            cnt++;
        }
        cout<<cnt<<endl;
    }
}
