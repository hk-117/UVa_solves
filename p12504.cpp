#include<bits/stdc++.h>
using namespace std;
map<string,string> parse_dict(string& dict){
    char *d= new char[dict.size()+1];
    map<string,string> words;
    strcpy(d,dict.c_str());
    char *t=strtok(d,"{:,}");
    while(t!=NULL){
        string st(t);
        t=strtok(NULL,"{:,}");
        string st1(t); 
        t=strtok(NULL,"{:,}");
        words[st]=st1;
    }
    return words;
}
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        map<string,string> d1,d2;
        set<string> added,deleted,changed;
        string dict1,dict2;
        getline(cin,dict1);
        getline(cin,dict2);
        d1=parse_dict(dict1);
        d2=parse_dict(dict2);
        for(auto it=d1.begin();it!=d1.end();it++){
            auto mt=d2.find(it->first);
            if( mt!= d2.end()){
                if(it->second != mt->second)
                    changed.insert(it->first);
            }
            else{
                deleted.insert(it->first);
            }
        }
        for(auto it=d2.begin();it!=d2.end();it++){
            auto mt=d1.find(it->first);
            if( mt== d1.end()){
                added.insert(it->first);
            }
        }
        if(!(added.size() || changed.size() || deleted.size())){
            cout<<"No changes"<<endl;
        }
        else{
            if(added.size()){
                cout<<"+";
                vector<string> a(added.begin(),added.end());
                for(auto it=a.begin();it!=a.end();it++){
                    cout<< *it ;
                    if(it != a.end()-1)
                        cout<<",";
                }
                cout<<endl;
            }
            if(deleted.size()){
                cout<<"-";
                vector<string> del(deleted.begin(),deleted.end());
                for(auto it=del.begin();it!=del.end();it++){
                    cout<< *it ;
                    if(it != del.end()-1)
                        cout<<",";
                }
                cout<<endl;
            }
            if(changed.size()){
                cout<<"*";
                vector<string>ch(changed.begin(),changed.end());
                for(auto it=ch.begin();it!=ch.end();it++){
                    cout<< *it ;
                    if(it != ch.end()-1)
                        cout<<",";
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
}
