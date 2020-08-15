#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sieve_size;
bitset<(2<<15+5)> C;
vector<int> P;
void sieve(ll n){
    sieve_size=n+1;
    C.set();
    C[0]=C[1]=0;
    for(ll i=2;i<=sieve_size;i++){
        if(C[i]){
            for(ll j=i*i;j<=sieve_size;j+=i){
                C[j]=0;
            }
            P.push_back((int)i);
        }
    }
}
int main(){
    int n;
    sieve(2<<15 +1);
    while(scanf("%d",&n)==1 && n){
        int cnt=0;
        for(int i=0;P[i] <= n/2 ;i++){
            if(binary_search(P.begin(),P.end(),n-P[i])){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}
