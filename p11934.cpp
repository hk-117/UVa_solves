#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int a,b,c,d,L;
    while(cin>>a>>b>>c>>d>>L,a||b||c||d||L){
        int cnt=0;
        R(i,0,L+1,1){
            int fx= a*i*i + b*i +c;
            if(fx%d==0)
                cnt++;
        }
        cout<<cnt<<endl;
    }
}
