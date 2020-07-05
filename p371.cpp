#include<bits/stdc++.h>
#define R(i,a,b,c) for(long long i=a;i<b;i+=c)
using namespace std;
long long cylen(long long n){
    long long res=0;
    do{
        if(n%2)
            n=3*n +1;
        else
            n=n/2;
        res++;
    }while(n!=1);
    return res;
}
int main(){
    long long a,b;
    while(cin>>a>>b,a||b){
        long long  mx=INT_MIN,res;
        if(a>b)
            swap(a,b);
        R(i,a,b+1,1){
            long long cyl= cylen(i);
            if(cyl>mx){
                mx=cyl;
                res=i;
            }
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<res<<" generates the longest sequence of "<<mx<<" values."<<endl;
    }
}
