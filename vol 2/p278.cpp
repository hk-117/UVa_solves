#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    char piece;
    int m,n;
    int t;
    cin>>t;
    while(t--){
        cin>>piece>>m>>n;
        if(piece=='r'){
            cout<<min(m,n)<<endl;
        }
        else if(piece=='Q'){
            cout<<min(m,n)<<endl;
        }
        else if(piece=='K'){
            cout<<((n+1)/2)*((m+1)/2)<<endl;
        }
        else{
            cout<<(m*n +1)/2<<endl;
        }
    }
}
