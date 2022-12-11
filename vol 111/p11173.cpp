#include<bits/stdc++.h>
using namespace std;

int main(){
    int cs;
    cin>>cs;
    while(cs--){
        int n,k;
        cin>>n>>k;
        printf("%d\n", k^(k>>1));
    }
}
