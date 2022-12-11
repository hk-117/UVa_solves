#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[15];
    int total=0,t;
    cin>>t;
    while(t--){
        int tmp;
        char op[7];
        cin>>op;
        if(strcmp(op,"donate")==0){
            cin>>tmp;
            total+=tmp;
        }
        else{
            cout<<total<<"\n";
        }
    }
    return 0;
}
