#include<bits/stdc++.h>
using namespace std;

int main(){
    string code;
    while(cin>>code, code !="#"){
        int sz=code.size();
        if(sz==2){
            if(code[0]<code[1]){
                next_permutation(code.begin(),code.end());
                cout<<code<<endl;
            }
            else
                cout<<"No Successor\n";
        }
        else{
            string prev=code;
            reverse(prev.begin(),prev.end());
            next_permutation(code.begin(),code.end());
            if(code==prev)
                cout<<"No Successor\n";
            else
                cout<< code<<endl;
        }
    }
}
