#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,position=0;
        cin>>n;
        int stored[n+5];
        string instruction;
        for(int i=0;i<n;i++){
            cin>>instruction;
            if(instruction=="LEFT"){
                position--;
                stored[i]=-1;
            }
            else if(instruction=="RIGHT"){
                position++;
                stored[i]=1;
            }
            else{
                int tmp;
                cin>>instruction>>tmp;
                int val=stored[tmp-1];
                position+=val;
                stored[i]=val;
            }
        }
        cout<<position<<"\n";
    }
}
