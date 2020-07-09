#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int chkrepeat(int i){
    map<char,int> freq;
    string in=to_string(i);
    R(j,0,in.size(),1){
        freq[in[j]]++;
        if(freq[in[j]]>1)
            return 0;
    }
    return 1;
}
int main(){
    int n,m;
    while(cin>>n>>m){
        int cnt=0;
        R(i,n,m+1,1){
            cnt+= chkrepeat(i);
        }
        cout<<cnt<<endl;
    }
}
