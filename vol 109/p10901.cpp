#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int cs;
    cin>>cs;
    while(cs--){
        int fcpct,tm,cars;
        cin>>fcpct>>tm>>cars;
        string bank="left";
        queue<pair<int,int>> lftbank,rgtbank;
        string arrivedon;
        int arrival,current_time=INT_MAX;
        R(i,0,cars,1){
            cin>>arrival>>arrivedon;
            if(arrival<current_time){
                current_time=arrival;
            }
            if(arrivedon=="left")
                lftbank.push(make_pair(i,arrival));
            else
                rgtbank.push(make_pair(i,arrival));
        }
        map <pair<int,int>,int> timesequence;
        while(!lftbank.empty() || !rgtbank.empty()){
            if(!lftbank.empty() && lftbank.front().second<=current_time){
                if(bank=="left"){
                    int i=1;
                    while(i<=fcpct && !lftbank.empty() && lftbank.front().second<=current_time){
                        timesequence[lftbank.front()]=current_time+tm;
                        i++;
                        lftbank.pop();
                    }
                    bank="right";
                    current_time+=tm;
                }
                else{
                    int i=1;
                    while(i<=fcpct && !rgtbank.empty() && rgtbank.front().second<=current_time){
                        timesequence[rgtbank.front()]=current_time+tm;
                        i++;
                        rgtbank.pop();
                    }
                    bank="left";
                    current_time+=tm;
                }
            }
            else if(!rgtbank.empty() && rgtbank.front().second<=current_time){
                if(bank=="left"){
                    int i=1;
                    while(i<=fcpct && !lftbank.empty() && lftbank.front().second<=current_time){
                        timesequence[lftbank.front()]=current_time+tm;
                        i++;
                        rgtbank.pop();
                    }
                    bank="right";
                    current_time+=tm;
                }
                else{
                    int i=1;
                    while(i<=fcpct && !rgtbank.empty() && rgtbank.front().second<=current_time){
                        timesequence[rgtbank.front()]=current_time+tm;
                        i++;
                        rgtbank.pop();
                    }
                    bank="left";
                    current_time+=tm;
                }
            }
            else if(current_time<lftbank.front().second || current_time<rgtbank.front().second){
                if(lftbank.empty()){
                    current_time=rgtbank.front().second;
                }
                else if(rgtbank.empty()){
                    current_time=lftbank.front().second;
                }
                else{
                    current_time= min(lftbank.front().second,rgtbank.front().second);
                }
            }
        }
        for(auto it=timesequence.begin();it!=timesequence.end();it++){
                cout<< (it->second)<<endl;
        }
        if(cs)
            cout<<endl;
    }
}
