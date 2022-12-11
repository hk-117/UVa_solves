#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int n;
    cin>>n;
    int lachimps[n];
    R(i,0,n,1){
        cin>>lachimps[i];
    }
    int q,h;
    cin>>q;
    R(i,0,q,1){
        cin>>h;
        auto sh= lower_bound(lachimps,lachimps+n,h);
        auto tl= upper_bound(lachimps,lachimps+n,h);
        sh--;
        if(sh==lachimps+n || sh-lachimps<0)
            cout<<'X'<<" ";
        else
            cout<< *sh <<" ";
        if(tl==lachimps+n)
            cout<<'X'<<endl;
        else
            cout<< *tl <<endl;
    }
}
