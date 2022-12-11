#include<cstdio>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll sieve_size;
bitset<10000010> C;
vector<int> P;
void sieve(int n){
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
    int n,sz;
    sieve(1000000);
    sz=P.size();
    while(scanf("%d",&n)==1 && n){
        bool found=false;
        int a,b;
        for(int i=0;P[i] < n && !found ;i++){
            b= n-P[i];
            if(binary_search(P.begin(),P.end(),b)){
                a=P[i];
                found=true;
            }
        }
        if(found){
            printf("%d = %d + %d\n",n,a,b);
        }
        else{
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
}
