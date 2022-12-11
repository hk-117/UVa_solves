#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        long int farmers,space,degree,total=0;
        cin>>farmers;
        while(farmers--){
            scanf("%ld %*ld %ld",&space,&degree);
            total+=space*degree;
        }
        cout<<total<<"\n";
    }
}
