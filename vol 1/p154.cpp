#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<map<char,char>> Cities;
    string inp;
    while(true){
        cin>>inp;
        if(inp[0]=='#')
            break;
        else if(inp[0]=='e'){
            int n=Cities.size(),mnpos,mn=INT_MAX;
            for(int i=0;i<n;i++){
                int tE=0;
                for(int j=0;j<n;j++){
                    if(i==j)
                        continue;
                    for(auto it=Cities[i].begin();it!=Cities[i].end();it++){
                        if(it->second != Cities[j][it->first])
                            tE++;
                    }
                }
                if(tE<mn){
                    mn=tE;
                    mnpos=i+1;
                }
            }
            cout<<mnpos<<endl;
            Cities.clear();
        }
        else{
            char a,b,c,d,e,f,g,h,i,j;
            map<char,char> C;
            sscanf(inp.c_str(),"%c/%c,%c/%c,%c/%c,%c/%c,%c/%c",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
            C[a]=b,C[c]=d,C[e]=f,C[g]=h,C[i]=j;
            Cities.push_back(C);
        }
    }
}
