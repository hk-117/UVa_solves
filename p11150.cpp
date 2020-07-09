#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int t= n/2 * 3;
        if(n%2)
            t++;
        cout<<t<<endl;
    }
}
