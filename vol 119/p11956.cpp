#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int t,tc=0;
    cin>>t;
    while(t--){
        tc++;
        string commands;
        cin>>commands;
        vector<int> ar(100);
        int pos=0;
        R(i,0,commands.size(),1){
            if(commands[i]=='+'){
                ar[pos]++;
                ar[pos]= ar[pos]>255 ? 0: ar[pos];
            }
            else if(commands[i]=='-'){
                ar[pos]--;
                ar[pos]=ar[pos] <0 ? 255: ar[pos];
            }
            else if(commands[i]=='<'){
                pos--;
                pos= pos <0 ? 99: pos;
            }
            else if(commands[i]=='>'){
                pos++;
                pos= pos>99 ? 0: pos;
            }
            else{
                continue;
            }
        }
        cout<<"Case "<<tc<<":";
        R(i,0,100,1){
            printf(" %02X",ar[i]);
        }
        cout<<endl;
    }
}
