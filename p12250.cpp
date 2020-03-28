#include<bits/stdc++.h>
using namespace std;

int main(){
    int c=1;
    char s[15];
    while(cin>>s){
        if(strcmp(s,"HELLO")==0){
            cout<<"Case "<<c<<": ENGLISH\n";
        }
        else if(strcmp(s,"HOLA")==0){
            cout<<"Case "<<c<<": SPANISH\n";
        }
        else if(strcmp(s,"HALLO")==0){
            cout<<"Case "<<c<<": GERMAN\n";
        }
        else if(strcmp(s,"BONJOUR")==0){
            cout<<"Case "<<c<<": FRENCH\n";
        }
        else if(strcmp(s,"CIAO")==0){
            cout<<"Case "<<c<<": ITALIAN\n";
        }
        else if(strcmp(s,"ZDRAVSTVUJTE")==0){
            cout<<"Case "<<c<<": RUSSIAN\n";
        }
        else if(strcmp(s,"#")==0){
            break;
        }
        else{
            cout<<"Case "<<c<<": UNKNOWN\n";
        }
        c++;
    }
    return 0;
}
