#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
bool fnc(string a,string b){
    return a+b > b+a;
}
int main(){
    int n;
    while(cin>>n,n){
        vector<string> numbers(n);
        for(int i=0;i<n;i++){
            cin>>numbers[i];
        }
        sort(numbers.begin(),numbers.end(),fnc);
        R(i,0,n,1){
            cout<<numbers[i];
        }
        cout<<endl;
    }
}
