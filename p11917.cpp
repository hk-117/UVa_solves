#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,tc=0;
    cin>>t;
    while(t--){
        tc++;
        int n;
        cin>>n;
        map<string,int> comforts;
        string sub;
        int ds;
        while(n--){
            cin>>sub>>ds;
            comforts[sub]=ds;
        }
        int d;
        cin>>d;
        string do_hw;
        cin>>do_hw;
        if(comforts[do_hw]){
            if(comforts[do_hw]<=d)
                cout<<"Case "<<tc<<": Yesss\n";
            else if(comforts[do_hw] <= d+5)
                cout<<"Case "<<tc<<": Late\n";
            else
                cout<<"Case "<<tc<<": Do your own homework!\n";
        }
        else{
            cout<<"Case "<<tc<<": Do your own homework!\n";
        }
    }
}
