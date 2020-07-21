#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool isPalindrome(string pl){
    int n=pl.size();
    R(i,0,n/2+1,1){
        if(pl[i]!=pl[n-1-i])
            return false;
    }
    return true;
}
int main(){
    int t,tc=0;
    cin>>t;
    cin.ignore();
    while(t--){
        tc++;
        string inp,plshid;
        getline(cin,inp);
        R(i,0,inp.size(),1){
            if(inp[i]>='a' && inp[i]<='z')
                plshid+=inp[i];
        }
        cout<<"Case #"<<tc<<":"<<endl;
        int sz=plshid.size();
        int sq=(int) sqrt((double)sz);
        if(sq*sq != sz){
            cout<<"No magic :("<<endl;
        }
        else{
            if(isPalindrome(plshid)){
                cout<<sq<<endl;
            }
            else{
                cout<<"No magic :("<<endl;
            }
        }
    }
}
