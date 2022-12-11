#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int cs,tc=0;
    cin>>cs;
    while(cs--){
        tc++;
        string inp;
        cin>>inp;
        stack<char> nodes;
        map<char,int> deg;
        nodes.push(inp[0]);
        R(i,1,inp.size(),1){
            if(nodes.top() != inp[i]){
                deg[nodes.top()]++;
                deg[inp[i]]++;
                nodes.push(inp[i]);
            }
            else{
                nodes.pop();
            }
        }
        printf("Case %d\n",tc);
        for(auto it=deg.begin();it!=deg.end();it++){
            if(it->second >0){
                printf("%c = %d\n",it->first,it->second);
            }
        }
    }
}
