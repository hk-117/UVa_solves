#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<string,string> slogans;
    cin>>n;
    cin.ignore();
    while(n--){
        string fst,snd;
        getline(cin,fst);
        getline(cin,snd);
        slogans[fst]=snd;
    }
    int q;
    cin>>q;
    cin.ignore();
    while(q--){
        string inp;
        getline(cin,inp);
        cout<< slogans[inp]<<endl;
    }
}
