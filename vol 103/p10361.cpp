#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    cin.ignore();
    while(N--){
        string inp,tmp;
        vector<string> W;
        int cnt=0,i;
        getline(cin,inp);
        tmp=inp;
        i=0;
        while(i<tmp.size()){
            if(tmp[i]=='<'){
                cnt++;
                string w;
                i++;
                while(tmp[i]!='>'){
                    cout<< tmp[i];
                    w+=tmp[i];
                    i++;
                }
                W.push_back(w);
                w="";
                i++;
                while(tmp[i]!='<' && i<tmp.size()){
                    cout<<tmp[i];
                    w+=tmp[i];
                    i++;
                }
                W.push_back(w);
            }
            else{
                cout<< tmp[i];
                i++;
            }
        }
        cout<<"\n";
        getline(cin,inp);
        for(int i=0;i<inp.size();i++){
            if(inp[i]!='.')
                cout<<inp[i];
        }
        cout<<W[2]<<W[1]<<W[0]<<W[3]<<"\n";
    }
}
