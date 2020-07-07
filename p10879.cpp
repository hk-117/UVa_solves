#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,tc=0;
    cin>>n;
    while(n--){
        tc++;
        long long k,sq;
        cin>>k;
        sq=sqrt(k)+2;
        int cnt=0;
        printf("Case #%d: %lld",tc,k);
        for(long long i=2;i<sq;i++){
            if(k%i==0){
                printf(" = %lld * %lld",i,k/i);
                cnt++;
                if(cnt==2)
                    break;
            }
        }
        puts("");
    }
}
