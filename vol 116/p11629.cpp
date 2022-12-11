#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool evaluate(map<string,int>&nrbachon,vector<string> &gs){
    double tot=0;
    R(i,0,gs.size()-2,1){
        tot+= nrbachon[gs[i]];
    }
    string cmp=gs[gs.size()-2];
    int vl= atoi(gs[gs.size()-1].c_str())*10;
    if(cmp=="<"){
        return tot<vl;
    }
    else if(cmp==">"){
        return tot>vl;
    }
    else if(cmp=="<="){
        return tot<=vl;
    }
    else if(cmp==">="){
        return tot>=vl;
    }
    else{
        return tot==vl;
    }
}
int main(){
    int p,g;
    cin>>p>>g;
    map<string,int> nrbachon;
    while(p--){
        string inp,tmp;
        int votes,it=0;
        cin>>inp>>tmp;
        stringstream ss(tmp);
        while(getline(ss,tmp,'.')){
            if(it%2==0){
                votes=atoi(tmp.c_str())*10;
                it++;
            }
            else{
                votes+= atoi(tmp.c_str());
            }
        }
        nrbachon[inp]=votes;
    }
    cin.ignore();
    R(i,0,g,1){
        string gs,prsed;
        vector<string> words;
        getline(cin,gs);
        stringstream ss(gs);
        while(ss>>prsed)
            words.push_back(prsed);
        if(evaluate(nrbachon,words)){
            printf("Guess #%d was correct.\n",i+1);
        }
        else
            printf("Guess #%d was incorrect.\n",i+1);
    }
}
