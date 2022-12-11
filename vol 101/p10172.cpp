#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int st;
    cin>>st;
    while(st--){
        int stations,ccapacity,qmax;
        cin>>stations>>ccapacity>>qmax;
        vector<queue<int>>cargoq(stations,queue<int>());
        R(i,0,stations,1){
            int ncrg;
            cin>>ncrg;
            while(ncrg--){
                int dm;
                cin>>dm;
                cargoq[i].push(dm);
            }
        }
        stack<int>carrier;
        int tm=0,i=0;
        while(i<stations){
            while(carrier.size()){
                if(!carrier.empty()){
                    if(i+1 ==carrier.top()){
                        carrier.pop();
                        tm++;
                    }
                    else{
                        if(cargoq[i].size()==qmax)
                            break;
                        cargoq[i].push(carrier.top());
                        tm++;
                        carrier.pop();
                    }
                }
            }
            bool done=true;
            R(k,0,stations,1){
                if(!cargoq[k].empty()){
                    done=false;
                    break;
                }
            }
            if(done && carrier.empty())
                break;
            R(j,carrier.size(),ccapacity,1){
                if(cargoq[i].empty())
                    break;
                carrier.push(cargoq[i].front());
                cargoq[i].pop();
                tm++;
            }
            i++;
            tm+=2;
            if(i>=stations){
                i=0;
            }
        }
        cout<<tm<<endl;
    }
}
