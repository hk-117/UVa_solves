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
int main(){
    int tc;
    sieve(1000000);
    scanf("%d",&tc);
    while(tc--){
        int n,m,sz;
        scanf("%d %d",&n,&m);
        vector<int> L(lower_bound(P.begin(),P.end(),n),upper_bound(P.begin(),P.end(),m));
        sz= L.size();
        if(sz<2){
            puts("No jumping champion");
        }
        else{
            map<int,int>F;
            int mx= INT_MIN,cnt=0,ans;
            for(int i=0;i<sz-1;i++){
                F[L[i+1]-L[i]]++;
                mx= max(mx,F[L[i+1]-L[i]]);
            }
            for(auto it=F.begin();it!=F.end();it++){
                if(it->second == mx){
                    cnt++;
                    ans=it->first;
                }
            }
            if(cnt>1){
                puts("No jumping champion");
            }
            else{
                printf("The jumping champion is %d\n",ans);
            }
        }
    }
}
