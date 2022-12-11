#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int l;
    while(cin>>l,l){
        string hw;
        cin>>hw;
        if(hw.find("Z")!=string::npos){
            cout<<0<<endl;
        }
        else{
            int prevpos=INT_MAX,dist=INT_MAX,nxtpos=INT_MAX;
            char prev='.';
            R(i,0,l,1){
                if(hw[i]!='.'){
                    if(prev!=hw[i]){
                        prevpos=nxtpos;
                        prev=hw[i];
                        nxtpos=i;
                    }
                    else{
                        prev=hw[i];
                        nxtpos=i;
                    }
                }
                else{
                    continue;
                }
                dist=min(dist, abs(prevpos-nxtpos));
            }
            cout<<dist<<endl;
        }
    }
}
