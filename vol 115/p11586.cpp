#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        string inp;
        getline(cin,inp);
        int m,f;
        m=count(inp.begin(),inp.end(),'M');
        f=count(inp.begin(),inp.end(),'F');
        if(m==f && m!=1 && f!=1)
            cout<<"LOOP"<<endl;
        else
            cout<<"NO LOOP"<<endl;
    }
}
