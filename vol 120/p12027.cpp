#include<bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    while(cin>>inp,inp!="0"){
        if(inp.size()==1){
            int num= inp[0]-'0';
            cout<< (int) sqrt(num)<<endl;
        }
        else{
            string nm;
            if(inp.size() %2){
                nm+=inp[0];
            }
            else{
                nm.assign(inp.begin(),inp.begin()+2);
            }
            int num;
            sscanf(nm.c_str(),"%d",&num);
            int ans = (int) sqrt(num);
            int zeros= (inp.size()-1)/2;
            cout<<ans;
            for(int i=1;i<=zeros;i++)
                cout<<0;
            cout<<endl;
        }
    }
}
