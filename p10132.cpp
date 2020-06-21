#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int tc;
    cin>>tc;
    cin.ignore();
    cin.ignore();
    while(tc--){
        vector<string> fragments;
        map<string,int> freqs;
        string inp;
        int n=0,sz,tot=0;
        while(getline(cin,inp),inp.size()!=0){
            n++;
            tot+=inp.size();
            fragments.push_back(inp);
        }
        sz= tot/(n/2);
        int mx=INT_MIN;
        R(i,0,fragments.size(),1){
            R(j,0,fragments.size(),1){
                if(i==j)
                    continue;
                string ot=fragments[i]+fragments[j];
                if(ot.size() == sz){
                    freqs[ot]++;
                    mx= mx>freqs[ot] ? mx : freqs[ot];
                }
            }
        }
        for(auto it=freqs.begin();it!=freqs.end();it++){
            if(it->second == mx){
                cout<< it->first << endl;
                break;
            }
        }
        if(tc)
            cout<<endl;
    }
}
