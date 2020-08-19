#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sieve_size;
bitset<10000010>C;
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
bool isPrime(ll N){
    if(N<=sieve_size) return C[N];
    for(ll i=0,rng=sqrt(N);i<P.size() && P[i]<=rng;i++){
        if(N%P[i]==0)
            return false;
    }
    return true;
}
int main(){
    ll l,h;
    sieve(10000000);
    while(scanf("%lld %lld",&l,&h)==2){
        vector<ll> Nprms;
        for(ll i=l;i<=h;i++){
            if(isPrime(i))
                Nprms.push_back(i);
        }
        if(Nprms.size()<2){
            puts("There are no adjacent primes.");
        }
        else{
            ll mnl,mnh,mxl,mxh,mxdf=-1,mndf=1000001;
            for(int i=0;i<Nprms.size()-1;i++){
                ll diff= Nprms[i+1]-Nprms[i];
                if(mxdf < diff){
                    mxdf= diff;
                    mxl=Nprms[i];
                    mxh=Nprms[i+1];
                }
                if(mndf>diff){
                    mndf=diff;
                    mnl=Nprms[i];
                    mnh=Nprms[i+1];
                }
            }
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",mnl,mnh,mxl,mxh);
        }
    }
}
