#include <bits/stdc++.h>
using namespace std;
map<string,set<string>>MP;
vector<string> vt={
    "C","C#","D","D#",
    "E","F","F#","G",
    "G#","A","A#","B"};
void makemap(){
    for(int i=0;i<vt.size();i++){
        int stps=0,j=i;
        while(stps<7){
            stps++;
            MP[vt[i]].insert(vt[j]);
            if(stps==3){
                j++;
            }
            else{
                j+=2;
            }
            j=j%12;
        }
    }
}
bool allBelongs(string st,set<string> setSt){
    for(auto it=setSt.begin();it!=setSt.end();it++){
        if(MP[st].find(*it)==MP[st].end())
            return false;
    }
    return true;
}
int main(){
    string line;
    makemap();
    while(getline(cin,line),line!="END"){
        stringstream ss(line);
        set<string> setSt;
        vector<string>Result;
        string inp;
        while(ss>>inp){
            setSt.insert(inp);
        }
        for(int i=0;i<vt.size();i++){
            if(allBelongs(vt[i],setSt)){
                Result.push_back(vt[i]);
            }
        }
        for(int i=0;i<Result.size();i++){
            if(i>0)
                cout<<" ";
            cout<<Result[i];
        }
        cout<<"\n";
    }
}
