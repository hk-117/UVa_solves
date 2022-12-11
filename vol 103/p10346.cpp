#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    while(cin>>n>>k){
        int t=n,but=n,nw;
        while(!(but<k)){
            nw= but/k;
            but%=k;
            but+= nw;
            t+=nw;
        }
        cout<<t<<endl;
    }
}
