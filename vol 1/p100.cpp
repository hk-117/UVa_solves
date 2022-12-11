#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int cylen(int n){
    int res=1;
    while(n!=1){
        if(n%2)
            n=3*n +1;
        else
            n=n/2;
        res++;
    }
    return res;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        int mx=INT_MIN,inita=a,initb=b;
        if(a>b)
            swap(a,b);
        R(i,a,b+1,1){
            int cyl= cylen(i);
            mx=max(mx,cyl);
        }
        cout<<inita<<" "<<initb<<" "<<mx <<endl;
    }
}
