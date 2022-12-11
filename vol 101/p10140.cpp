#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sieve_size;
bitset<20000010>C;
vector<int> P;
vector<pair<int,int>> PP;
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
bool isPrime(ll N){
    if(N<=sieve_size) return C[N];
    for(ll i=0,rng=sqrt(N);i<P.size() && P[i]<=rng;i++){
        if(N%P[i]==0)
            return false;
    }
    return true;
}
void twnPairs(){
    ll a,b,i=3;
    for(ll i=3;i<=20000000;i+=2){
        if(isPrime(i) && isPrime(i+2)){
            PP.push_back(make_pair(i,i+2));
        }
    }
}
int main(){
    int n;
    sieve(20000000);
    twnPairs();
    while(scanf("%d",&n)==1){
        ll a= PP[n-1].first,b=PP[n-1].second;
        printf("(%lld, %lld)\n",a,b);
    }
}
