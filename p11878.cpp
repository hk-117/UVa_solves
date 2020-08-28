#include<bits/stdc++.h>
using namespace std;
int main(){
    string E;
    int cnt=0;
    while(cin>>E){
        bool adi=false;
        int a,b;
        string d;
        for(int i=0;i<E.size();i++){
            if(E[i]>='0' && E[i]<='9'){
                d+=E[i];
            }
            else if(E[i]=='+'){
                adi=true;
                a=atoi(d.c_str());
                d="";
            }
            else if(E[i]=='-'){
                a=atoi(d.c_str());
                d="";
            }
            else{
                b=atoi(d.c_str());
                d="";
            }
        }
        if(adi){
            if(a+b == atoi(d.c_str())){
                cnt++;
            }
        }
        else{
            if(a-b == atoi(d.c_str())){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
