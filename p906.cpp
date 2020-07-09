#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,d;
    double n;
    while(cin>>a>>b){
        cin>>n;
        long double rat1=(long double)a/b,rat2;
        long long st= (long long) (1.0/(n*b));
        for(d=st;;d++){
            c=(long long)(rat1*d);
            while(a*d>=b*c)c++;
            rat2= (long double) c/d;
            if((rat2-rat1)<=n){
                cout<<(long long)c<<" "<<(long long)d<<endl;
                break;
            }
        }
    }
}
