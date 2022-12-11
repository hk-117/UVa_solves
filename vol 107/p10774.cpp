#include<bits/stdc++.h>
using namespace std;
long long findAns(bitset<32> &n){
    for(int i=31;i>=0;i--){
        if(n[i]==1){
            n.reset(i);
            break;
        }
    }
    n=n<<1;
    n|=1;
    return n.to_ulong();
}
int main(){
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        int n,i=0;
        long long res;
        tc++;
        scanf("%d",&n);
        while(true){
            bitset<32> N(n);
            res=findAns(N);
            if(res==n)
                break;
            else
                n=res;
            i++;
        }
        printf("Case %d: %d %d\n",tc,i,n);
    }
}
