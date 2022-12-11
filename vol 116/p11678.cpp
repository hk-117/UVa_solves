#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b,a||b){
        set<int> A[2];
        int inp;
        R(i,0,a,1){
            cin>>inp;
            A[0].insert(inp);
        }
        R(i,0,b,1){
            cin>>inp;
            A[1].insert(inp);
        }
        bool lp= (A[0].size()>A[1].size());
        int cnt=0;
        for(auto it=A[lp].begin();it!=A[lp].end();it++){
            if(A[!lp].find(*it) == A[!lp].end())
                cnt++;
        }
        cout<<cnt<<endl;
    }
}
