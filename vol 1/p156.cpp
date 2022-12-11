#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
void allToLower(string &s){
    R(i,0,s.size(),1){
        s[i]=tolower(s[i]);
    }
}
int main(){
    string inp,total;
    while(getline(cin,inp),inp!="#"){
        total+=inp+" ";
    }
    stringstream ss(total);
    string dm;
    map<string,bool> anana,all;
    vector <string> sortedAll;
    while(ss>>dm){
        all[dm]=true;
        string s=dm;
        allToLower(s);
        sort(s.begin(),s.end());
        sortedAll.push_back(s);
    }
    for(auto it=all.begin();it!=all.end();it++){
        string st=it->first;
        allToLower(st);
        sort(st.begin(),st.end());
        if(count(sortedAll.begin(),sortedAll.end(),st)==1){
            anana[it->first]=true;
        }
    }
    for(auto it=anana.begin();it!=anana.end();it++){
        cout<< it->first <<endl;
    }
}
