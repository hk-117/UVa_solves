#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
vector<vector<int>> Graph(300);
bool status[300]={false};
long long k;
int dfs(int mntr,int putcandle,int ths){
    status[mntr]= !((++putcandle)%k);
    R(i,0,(int)Graph[mntr].size(),1){
        int vt= Graph[mntr][i];
        if(!status[vt] && (vt!=ths)){
            if(status[mntr]){
                cout<<(char) mntr<<" ";
            }
            return dfs(vt,putcandle,mntr);
        }
    }
    cout<<"/"<< (char) mntr<<endl;
    return 0;
}
int main(){
    string inp;
    while(getline(cin,inp),inp!="#"){
        stringstream ss(inp);
        string labyrinth;
        char mntr,ths;
        ss>>labyrinth>>mntr>>ths>>k;
        labyrinth[labyrinth.size()-1]=';';
        stringstream cavern(labyrinth);
        string acavern;
        while(getline(cavern,acavern,';')){
            char nd;
            char *p= new char[acavern.size()];
            sscanf(acavern.c_str(),"%c:%s",&nd,p);
            string passages(p);
            R(i,0,passages.size(),1){
                Graph[nd].push_back(passages[i]);
            }
        }
        dfs(mntr,0,ths);
        ms(status,false);
        R(i,0,300,1)
            Graph[i].clear();
    }
}
