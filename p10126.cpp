#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,nl=false;
    while(cin>>N){
        string line;
        map<string,int> C;
        cin.ignore();
        if(nl)
            cout<<"\n";
        else
            nl=true;
        while(getline(cin,line),line!="EndOfText"){
            string w;
            for(int i=0;i<line.size();i++){
                if(isalpha(line[i])){
                    w+=tolower(line[i]);
                    if(i==line.size()-1){
                        C[w]++;
                    }
                }
                else{
                    C[w]++;
                    w="";
                }
            }
        }
        int wc=0;
        for(auto it=C.begin();it!=C.end();it++){
            if(it->second == N){
                wc++;
                cout<< it->first <<"\n";
            }
        }
        if(wc==0)
            cout<<"There is no such word.\n";
    }
}
