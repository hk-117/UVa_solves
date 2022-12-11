#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        int drnk=0;
        while(n>1){
            int nw=n/3;
            drnk += nw;
            n=n%3 + nw;
            if(n<3){
                if(n%3==2)
                    n++;
            }
        }
        cout<<drnk<<endl;
    }
}
