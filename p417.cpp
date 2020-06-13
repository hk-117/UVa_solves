#include<bits/stdc++.h>
using namespace std;

map<string,int> Wnumbers;

void generate_positions(){
    queue<string> Q;
    for(char c='a';c<='z';c++) Q.push(string(1,c));

    string s;

    int cont=1;

    while(!Q.empty()){
        s=Q.front();
        Q.pop();

        Wnumbers[s]=cont;
        cont++;

        if(s.size()==5) continue;

        for(char c=s[s.size()-1]+1;c<='z';c++) Q.push(s+c);
    }
}
int main(){
    generate_positions();
    string inp;
    while(cin>>inp){
        cout<< Wnumbers[inp]<<endl;
    }
}
