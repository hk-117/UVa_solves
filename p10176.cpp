#include<bits/stdc++.h>
using namespace std;
int DP[10005];
int fill(int k){
    if(DP[k]!= -1)
        return DP[k];
    if(k==1)
        return DP[k]=2;
    else
        return DP[k]=(2*(fill(k-1)))%131071;
}
int findMod(string N){
    int m=0,sz=N.size();
    for(int i=0;i<=sz-2;i++){
        if(N[i]!='0'){
            m= (m+ DP[sz-2-i])%131071;
        }
    }
    return m;
}
int main(){
    string line,Num;
    memset(DP,-1,sizeof DP);
    DP[0]=1;
    int tmp=fill(10000);
    while(cin>>line){
        if(line[line.size()-1]=='#'){
            Num+=line;
            if(!findMod(Num)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
            Num="";
        }
        else{
            Num+=line;
        }
    }
}
