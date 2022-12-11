#include<bits/stdc++.h>
using namespace std;

int main(){
    int c=1;
    char s[15];
    while(cin>>s){
        if(strcmp(s,"Hajj")==0){
            cout<<"Case "<<c<<": Hajj-e-Akbar\n";
        }
        else if(strcmp(s,"Umrah")==0){
            cout<<"Case "<<c<<": Hajj-e-Asghar\n";
        }
        else if(strcmp(s,"*")==0){
            break;
        }
        c++;
    }
    return 0;
}
