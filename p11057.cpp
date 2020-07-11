#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int p[n];
        map<int,int>frq;
        R(i,0,n,1){
            cin>>p[i];
            frq[p[i]]++;
        }
        int hs;
        cin>>hs;
        cin.ignore();
        sort(p,p+n);
        int a=p[0],b=p[n-1],diff=b-a;
        R(i,0,n,1){
            int tmp=hs-p[i];
            if(tmp==p[i] && frq[tmp]<2)
                continue;
            if(binary_search(p,p+n,tmp)){
                bool chk1,chk2;
                if(diff>abs(p[i]-tmp)){
                    a=p[i];
                    b=tmp;
                    diff=abs(p[i]-tmp);
                }
            }
        }
        cout<<"Peter should buy books whose prices are "<<a<<" and "<<b<<"."<<endl;
        puts("");
    }
}
