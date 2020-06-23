#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int k,tc=0;
    cin>>k;
    while(k--){
        tc++;
        map<int,set<int>> uni;
        set<int> ctrl;
        int n,m;
        cin>>n;
        R(i,0,n,1){
            uni[i];
            cin>>m;
            while(m--){
                int dm;
                cin>>dm;
                if(ctrl.find(dm) == ctrl.end()){
                    ctrl.insert(dm);
                    uni[i].insert(dm);
                }
                else{
                    for(auto it=uni.begin();it!=uni.end();it++){
                        if(it->first != i){
                            (it->second).erase(dm);
                        }
                    }
                    ctrl.insert(dm);
                }
            }
        }
        int total=0;
        for(auto it=uni.begin();it!=uni.end();it++){
            total+= (it->second).size();
        }
        cout<<"Case "<<tc<<":";
        for(auto it=uni.begin();it!=uni.end();it++){
            int sz= (it->second).size();
            double pcnt=((double) sz / (double) total) *100 ;
            cout<<" "<< fixed<<pcnt <<"%";
        }
        cout<<endl;
    }
}
