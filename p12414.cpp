#include<bits/stdc++.h>
using namespace std;
string calcYun(string N){
    while(N.size()>2 && N!="100"){
        string tmp;
        for(int i=0;i<N.size()-1;i++){
            int adi= N[i]-'0'+N[i+1]-'0';
            tmp+=('0'+(adi%10));
        }
        N=tmp;
    }
    return N;
}
int main(){
    string AB;
    while(cin>>AB){
        bool found=false;
        int res;
        for(int i=1;i<=10000 && !found ;i++){
            string N;
            for(int j=0;j<AB.size();j++){
                N+= to_string(i+AB[j]-'A');
            }
            string yun=calcYun(N);
            if(yun=="100"){
                found=true;
                res=i;
            }
        }
        if(found)
            cout<< res <<"\n";
        else
            cout<< ":(\n";
    }
}
