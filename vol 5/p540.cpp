#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int t,scene=0;
    while(cin>>t,t){
        scene++;
        map<int,int> teams;
        R(i,0,t,1){
            int sz;
            cin>>sz;
            while(sz--){
                int element;
                cin>>element;
                teams[element]=i;
            }
        }
        vector<int> tmq;
        map<int,queue<int>> teamnow;
        string command;
        cout<<"Scenario #"<<scene<<endl;
        while(cin>>command,command!="STOP"){
            if(command=="ENQUEUE"){
                int part;
                cin>>part;
                teamnow[teams[part]].push(part);
                auto it=find(tmq.begin(),tmq.end(),teams[part]);
                if(it==tmq.end())
                    tmq.push_back(teams[part]);
            }
            else{
                if(tmq.size()){
                    cout<<teamnow[tmq[0]].front()<<endl;
                    teamnow[tmq[0]].pop();
                    if(teamnow[tmq[0]].empty()){
                        tmq.erase(tmq.begin());
                    }
                }
            }
        }
        cout<<endl;
    }
}
