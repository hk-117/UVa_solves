#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int inp;
    while(cin>>inp){
        bitset<32> stored(inp);
        string str= stored.to_string();
        vector<string> rev;
        int st=0,nd=8;
        R(i,0,4,1){
            string a(str.begin()+st,str.begin()+nd);
            rev.push_back(a);
            st+=8;
            nd+=8;
        }
        reverse(rev.begin(),rev.end());
        string fn="";
        R(i,0,rev.size(),1){
            fn+=rev[i];
        }
        bitset<32> fin(fn);
        bool outnegative=false;
        if(fin.test(31)){
            fin.flip();
            outnegative=true;
        }
        cout<< inp<<" converts to ";
        if(outnegative){
            int ng= fin.to_ulong() +1;
            cout<< -ng <<endl;
        }
        else{
            cout<< fin.to_ulong() <<endl;
        }
    }
}
