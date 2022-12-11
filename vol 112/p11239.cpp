#include<bits/stdc++.h>
using namespace std;
bool fnc(pair<int,string> p1, pair<int,string> p2){
    if(p1.first==p2.first)
        return p1.second<p2.second;
    else
        return p1.first>p2.first;
}
int main(){
    string project_name;
    map<string,set<string>> sign;
    set<string>central;
    vector<pair<int,string>> out;
    while(getline(cin,project_name), project_name!="0"){
        string studs;
        sign[project_name];
        while(getline(cin,studs),studs!="1"){
            if(isupper(studs[0])){
                project_name=studs;
                sign[project_name];
            }
            else{
                bool dup=false;
                for(auto it=sign.begin();it!=sign.end();it++){
                    if((it->first != project_name) && ((it->second).find(studs) != (it->second).end())){
                        (it->second).erase(studs);
                        dup=true;
                        break;
                    }
                    else if(central.find(studs) != central.end()){
                        dup=true;
                    }
                }
                if(!dup){
                    central.insert(studs);
                    sign[project_name].insert(studs);
                }
            }
        }
        for(auto it=sign.begin();it!=sign.end();it++){
            out.push_back(make_pair((it->second).size(),it->first));
        }
        sort(out.begin(),out.end(),fnc);
        for(auto it=out.begin();it!=out.end();it++){
            cout<< it->second <<" "<< it->first <<endl;
        }
        sign.clear();
        out.clear();
        central.clear();
    }
}
