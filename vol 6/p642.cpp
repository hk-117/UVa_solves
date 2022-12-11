#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    vector<string> dict;
    string inp;
    while(cin>>inp,inp!="XXXXXX"){
        dict.push_back(inp);
    }
    string test;
    while(cin>>test,test!="XXXXXX"){
        set<string> Scrm;
        string a=test;
        sort(a.begin(),a.end());
        R(i,0,dict.size(),1){
            string b=dict[i];
            sort(b.begin(),b.end());
            if(a==b){
                Scrm.insert(dict[i]);
            }
        }
        if(Scrm.size()){
            for(auto it=Scrm.begin();it!=Scrm.end();it++){
                cout<< *it <<endl;
            }
            puts("******");
        }
        else{
            puts("NOT A VALID WORD");
            puts("******");
        }
    }
}
