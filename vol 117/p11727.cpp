#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,c=1;
    cin>>t;
    while(t--){
        int arr[3];
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(arr,arr+3);
        cout<<"Case "<<c<<": "<<arr[1]<<"\n";
        c++;
    }
    return 0;
}
