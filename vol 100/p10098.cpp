#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        string inp;
        cin>>inp;
        sort(inp.begin(),inp.end());
        do{
            cout<<inp<<endl;
        }while(next_permutation(inp.begin(),inp.end()));
        cout<<endl;
    }
}
