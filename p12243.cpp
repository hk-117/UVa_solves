#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    while(getline(cin,S),S!="*"){
        stringstream ss(S);
        string tmp;
        bool t=true;
        char c=tolower(S[0]);
        while(ss>>tmp){
            if(tolower(tmp[0])!=c){
                t=false;
                break;
            }
        }
        if(t)
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
}
