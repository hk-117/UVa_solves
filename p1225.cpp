#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string number;
        map<int,int>freqs;
        int n;
        cin>>n;
        R(i,1,n+1,1){
            number+=to_string(i);
        }
        R(i,0,number.size(),1){
            freqs[number[i]-'0']++;
        }
        cout<< freqs[0];
        R(i,1,10,1){
            cout<<" " <<freqs[i];
        }
        cout<<endl;
    }
}
