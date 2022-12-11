#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int l,m;
        cin>>l>>m;
        l*=100;
        queue<int> lftbank,rgtbank;
        string bank="left",bnk;
        int lnt;
        R(i,0,m,1){
            cin>>lnt>>bnk;
            if(bnk=="left")
                lftbank.push(lnt);
            else
                rgtbank.push(lnt);
        }
        int crosses=0;
        while(!lftbank.empty() || !rgtbank.empty()){
            if(bank=="left"){
                int cpct=l;
                while(!lftbank.empty() && lftbank.front()<=cpct){
                    cpct -= lftbank.front();
                    lftbank.pop();
                }
                bank="right";
                crosses++;
            }
            else{
                int cpct=l;
                while(!rgtbank.empty() && rgtbank.front()<=cpct){
                    cpct -=rgtbank.front();
                    rgtbank.pop();
                }
                bank="left";
                crosses++;
            }
        }
        cout<<crosses<<endl;
    }
}
