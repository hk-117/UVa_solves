#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int cn;
        cin>>cn;
        string awake;
        cin>>awake;
        map<char,bool> initial;
        map<char,int> alive_connection_freq;
        vector<pair<char,char>> sleeping;
        R(i,0,awake.size(),1){
            initial[awake[i]]=true;
        }
        string cpair;
        R(i,0,cn,1){
            cin>>cpair;
            char a=cpair[0],b=cpair[1];
            if(!initial[a]){
                if(!initial[b]){
                    sleeping.push_back(make_pair(a,b));
                }
                else{
                    alive_connection_freq[a]++;
                }
            }
            else{
                if(!initial[b]){
                    alive_connection_freq[b]++;
                }
                else{
                    continue;
                }
            }
        }
        int year=0,stat=3;
        bool ache=true;
        while(alive_connection_freq.size() && ache){
            bool flag=false;
            vector<char> erase_map;
            for(auto it=alive_connection_freq.begin();it!=alive_connection_freq.end();it++){
                if( it->second >= 3 ){
                    flag=true;
                    initial[it->first]=true;
                    stat++;
                    erase_map.push_back(it->first);
                }
            }
            for(auto it=sleeping.begin();it!=sleeping.end();it++){
                char a=it->first,b=it->second;
                if(!initial[a]){
                    if(!initial[b]){
                        continue;
                    }
                    else{
                        alive_connection_freq[a]++;
                        sleeping.erase(it);
                        it--;
                    }
                }
                else{
                    if(!initial[b]){
                        alive_connection_freq[b]++;
                        sleeping.erase(it);
                        it--;
                    }
                    else{
                        sleeping.erase(it);
                        it--;
                    }
                }
            }
            if(!flag){
                ache=false;
            }
            else{
                R(i,0,erase_map.size(),1){
                    alive_connection_freq.erase(erase_map[i]);
                }
                year++;
            }
        }
        if(stat == n){
            cout<<"WAKE UP IN, "<<year<<", YEARS"<<endl;
        }
        else{
            cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
        }
        cin.ignore();
    }
}
