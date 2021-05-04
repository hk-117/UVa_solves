#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    string S,B,st;
    while(N--){
        cin>>S;
        int s=S.size(),len;
        len=s;
        while(true){
            s--;
            B.assign(S,0,s);
            st.assign(S,s,len);
            if(st.find(B)!=string::npos)
                break;
        }
        int bs=B.size(),step=0,bpos;
        bpos=len;
        while(step<8){
            cout<< B[bpos%bs];
            bpos++;
            step++;
        }
        cout<<"...\n";
    }
}
