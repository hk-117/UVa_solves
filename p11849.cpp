#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m, n||m){
        map<int,bool>jack;
        R(i,0,n,1){
            int cd;
            cin>>cd;
            jack[cd]=true;
        }
        int sell=0;
        R(i,0,m,1){
            int cd;
            cin>>cd;
            if(jack[cd])
                sell++;
        }
        cout<<sell<<endl;
    }
}
