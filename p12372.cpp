#include<bits/stdc++.h>
using namespace std;

int main(){
    int c=1,t;
    cin>>t;
    while(t--){
        int height,width,thickness;
        cin>>height>>width>>thickness;
        
        if(height<=20 && width<=20 && thickness<=20){
            cout<<"Case "<<c<<": good\n";
        }
        else{
            cout<<"Case "<<c<<": bad\n";
        }
        c++;
    }
    return 0;
}
