#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    string stk;
    int tc=0;
    while(cin>>stk,stk!="end"){
        tc++;
        vector<stack<char>> need(26,stack<char>());
        need[0].push(stk[0]);
        int cnt=1;
        bool pushed=false;
        R(i,1,stk.size(),1){
            pushed=false;
            R(j,0,26,1){
                if(!need[j].empty() && stk[i]<=need[j].top()){
                    need[j].push(stk[i]);
                    pushed=true;
                    break;
                }
            }
            if(!pushed){
                need[cnt++].push(stk[i]);
            }
        }
        cout<<"Case "<<tc<<": "<<cnt<<endl;
    }
}
