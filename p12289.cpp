#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    char s[6];
    while(t--){
        cin>>s;
        if(strlen(s)==5)
            cout<<3<<endl;
        else{
            if(strstr(s,"on")||strstr(s,"ne")||(s[0]=='o' && s[2]=='e'))
                cout<<1<<"\n";
            else
                cout<<2<<"\n";
        }
    }
}
