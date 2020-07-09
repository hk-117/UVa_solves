#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m,x;
    while(cin>>m>>x,m||x){
        long long st;
        if(x==100){
            cout<<"Not found"<<endl;
            continue;
        }
        st= ceil((double)m/(1-x/100.0))+5;
        while(st*(100-x) >= (m-1)*100){
            st--;
        }
        if(st <= m-1)
            cout<<"Not found"<<endl;
        else
            cout<< st <<endl;
    }
}
