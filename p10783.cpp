#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc,t=0;
    cin>>tc;
    while(tc--){
        t++;
        int a,b,sum=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++){
            if(i%2)
                sum+=i;
        }
        printf("Case %d: %d\n",t,sum);
    }
}
