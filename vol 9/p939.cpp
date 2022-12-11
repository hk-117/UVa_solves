#include<bits/stdc++.h>
using namespace std;
void change_status(map<string,vector<string>> &relations,map<string,string> &status,string name){
    if( status[name]=="dominant" || status[name]=="recessive" || status[name]=="non-existent"){
        return;
    }
    else{
        string name1= relations[name][0],name2=relations[name][1];
        if(status[name1]!="dominant" || status[name1]!="recessive" || status[name1]!="non-existent"){
            change_status(relations,status,name1);
        }
        if(status[name2]!="dominant" || status[name2]!="recessive" || status[name2]!="non-existent"){
            change_status(relations,status,name2);
        }
        if(status[name1]!="non-existent" || status[name2]!="non-existent"){
            if(status[name1]=="dominant" && status[name2]=="dominant"){
                status[name]="dominant";
            }
            else if(status[name1]=="recessive" && status[name2]=="dominant"){
                status[name]="dominant";
            }
            else if(status[name1]=="dominant" && status[name2]=="recessive"){
                status[name]="dominant";
            }
            else if(status[name1]=="recessive" && status[name2]=="recessive"){
                status[name]="recessive";
            }
            else if(status[name1]=="dominant" && status[name2]=="non-existent"){
                status[name]="recessive";
            }
            else if(status[name1]=="non-existent" && status[name2]=="dominant"){
                status[name]="recessive";
            }
            else{
                status[name]="non-existent";
            }
        }
        else{
            status[name]="non-existent";
        }
    }
}
int main(){
    int n;
    cin>>n;
    map<string,string> status;
    map<string,vector<string>>relations;
    vector<string> names;
    while(n--){
        string s1,s2;
        cin>>s1>>s2;
        if(s2=="dominant" || s2=="non-existent" || s2=="recessive"){
            status[s1]=s2;
        }
        else{
            relations[s2].push_back(s1);
            if(find(names.begin(),names.end(),s2) == names.end())
                names.push_back(s2);
        }
    }
    for(auto it=names.begin();it!=names.end();it++){
        if( status[*it]=="dominant" || status[*it]=="recessive" || status[*it]=="non-existent")
            continue;
        else
            change_status(relations,status,*it);
    }
    for(auto it=status.begin();it!=status.end();it++){
        cout<< it->first <<" "<<it->second <<endl;
    }
}
