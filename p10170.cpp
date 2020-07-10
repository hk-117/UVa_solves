#include<bits/stdc++.h>
using namespace std;
int main(){
    long long s,d;
    while(cin>>s>>d){
        long long ans =0;
        while(true){
            ans+= s;
            if(ans>=d){
                cout<<s<<endl;
                break;
            }
            s++;
        }
    }
}
