#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,tc=0;
    cin>>t;
    while(t--){
        tc++;
        long long sw,n;
        cin>>n;
        sw= (n*(n-1))/2;
        printf("Case %d: ",tc);
        if(sw%2){
            printf("%lld/%d\n",sw,2);
        }
        else{
            printf("%lld\n",sw/2);
        }
    }
}
