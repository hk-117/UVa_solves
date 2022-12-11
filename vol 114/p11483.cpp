#include<bits/stdc++.h>
using namespace std;
void printLine(string inp){
    for(int i=0;i<inp.size();i++){
        if(inp[i]=='\"')
            cout<<"\\\"";
        else if(inp[i]=='\\')
            cout<<"\\\\";
        else
            cout<< inp[i];
    }
}
int main(){
    int T,tc=0;
    while(cin>>T,T){
        printf("Case %d:\n",++tc);
        cout<<"#include<string.h>\n";
        cout<<"#include<stdio.h>\n";
        cout<<"int main()\n";
        cout<<"{\n";
        string inp;
        cin.ignore();
        while(T--){
            getline(cin,inp);
            cout<<"printf(\"";
            printLine(inp);
            cout<<"\\n\");\n";
        }
        cout<<"printf(\"\\n\");\n";
        cout<<"return 0;\n";
        cout<<"}\n";
    }
}
