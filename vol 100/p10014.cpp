#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
        int n;
        double ao,ano;
        cin>>n>>ao>>ano;
        double cs[n];
        R(i,0,n,1){
            cin>>cs[i];
        }
        cin.ignore();
        double ans=0;
        ans+= n*ao+ano;
        R(i,0,n,1){
            ans-= 2*(i+1)*cs[n-1-i];
        }
        ans= ans/(n+1);
        printf("%.2lf\n",ans);
        if(tc)
            puts("");
    }
}
