#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int e,f,c,soda=0,total;
        cin>>e>>f>>c;
        total=e+f;
        while(total>=c){
            int nw=total/c;
            soda += nw;
            total= (total%c) + nw;
        }
        cout<<soda<<endl;
    }
}
