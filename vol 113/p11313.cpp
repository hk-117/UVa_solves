#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,m,round=0,rem=0;
        cin>>n>>m;
        if(n<m)
            cout<<"cannot do this"<<endl;
        else{
            while(n>=m){
                n=(n-m)+1;
                round++;
            }
            if(n==1){
                cout<<round<<endl;
            }
            else{
                cout<<"cannot do this"<<endl;
            }
        }
    }
}
