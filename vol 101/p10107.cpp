#include<bits/stdc++.h>
#define R(i,a,b,c) for(long long i=a;i<b;i+=c)
using namespace std;
typedef long long ll;

int main(){
    ll tmp;
    vector<ll> dnmc;
    while(cin>>tmp){
        dnmc.push_back(tmp);
        sort(dnmc.begin(),dnmc.end());
        int n=dnmc.size();
        if(n%2){
            cout<<dnmc[(n-1)/2]<<endl;
        }
        else{
            cout<<(dnmc[(n-1)/2] +dnmc[(n-1)/2 +1])/2 <<endl;
        }
    }
}
