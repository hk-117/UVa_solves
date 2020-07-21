#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool isPalindrome(string pl){
    int n=pl.size();
    R(i,0,n/2+1,1){
        if(pl[i]!=pl[n-1-i])
            return false;
    }
    return true;
}
int main(){
    string inp;
    while(getline(cin,inp),inp!="DONE"){
        int sz=inp.size();
        string plshid;
        R(i,0,sz,1){
            if((inp[i]>='a' && inp[i]<='z')||(inp[i]>='A' && inp[i]<='Z')){
                plshid+= tolower(inp[i]);
            }
        }
        if(isPalindrome(plshid)){
            cout<<"You won't be eaten!"<<endl;
        }
        else{
            cout<<"Uh oh.."<<endl;
        }
    }
}
