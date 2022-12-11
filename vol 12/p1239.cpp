#include<bits/stdc++.h>
using namespace std;
string S;
int K;
int LargestPal(string str){
    int len=str.size()-1,cnt=0,i,j=0;
    i=len/2;
    while(i>=0 && cnt<=K){
        if(str[i]!=str[len-i])
            cnt++;
        i--;
        if(cnt<=K)
            j++;
    }
    if(len%2==0)
        return 2*j-1;
    return 2*j;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string tmp;
        int len,res=0;
        cin>>S>>K;
        len=S.size();
        for(int i=0;i<len;i++){
            int l=i-0,r=len-i-1,tmr;
            if(l<r){
                tmp.assign(S,0,2*l+1);
            }
            else if(l>r){
                tmp.assign(S,i-r,2*r+1);
            }
            else
                tmp=S;
            tmr=LargestPal(tmp);
            if(tmr>res)
                res=tmr;
            if(l<r && (2*l+2 <= len)){
                tmp.assign(S,0,2*l+2);
            }
            else if(l>r && (i-r-1)>=0){
                tmp.assign(S,i-r-1,2*l+2);
            }
            tmr=LargestPal(tmp);
            if(tmr>res)
                res=tmr;
        }
        cout<< res <<"\n";
    }
}
