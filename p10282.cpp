#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,string> dict;
    string inp,bdesh,desh,khbr;
    while(getline(cin,inp),inp.size()!=0){
        stringstream ss(inp);
        ss>>desh>>bdesh;
        dict[bdesh]=desh;
    } 
    while(cin>>khbr){
        if(dict[khbr]=="")
            cout<<"eh"<<endl;
        else
            cout<<dict[khbr]<<endl;
    }
}
