#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
map<string,bool> Ocrd;
map<pair<int,string>,int>Wos;
int mx=0;
void manipul(string &line,int i){
    char * ln= new char[line.size()+1];
    strcpy(ln,line.c_str());
    char *wrd= strtok(ln," @#\"\'.,!?0123456789");
    Wos[make_pair(i,line)]=0;
    while(wrd!=0){
        string wd(wrd);
        R(i,0,wd.size(),1){
            wd[i]=tolower(wd[i]);
        }
        if(Ocrd[wd]){
            Wos[make_pair(i,line)]++;
            mx= max(Wos[make_pair(i,line)],mx);
        }
        wrd= strtok(NULL," @#\"\'.,!?0123456789");
    }
}
int main(){
    int k,e,st=0;
    while(cin>>k>>e){
        st++;
        Ocrd.clear();
        Wos.clear();
        string line;
        R(i,0,k,1){
            cin>>line;
            Ocrd[line]=true;
        }
        cin.ignore();
        R(i,0,e,1){
            getline(cin,line);
            manipul(line,i);
        }
        cout<<"Excuse Set #"<<st<<endl;
        for(auto it=Wos.begin();it!=Wos.end();it++){
            if(it->second == mx){
                cout<< it->first.second <<endl;
            }
        }
        cout<<endl;
        mx=0;
    }
}
