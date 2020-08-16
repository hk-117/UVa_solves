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
bool isAnagram(int nm,int &rs,int n){
    string a= to_string(nm);
    rs=nm;
    sort(a.begin(),a.end());
    do{
        nm= atoi(a.c_str());
        if(!C[nm]){
            return false;
        }
    }while(next_permutation(a.begin(),a.end()));
    return true;
}
int chkAnagram(vector<int> &lst,int n){
    int sz=lst.size(),rs;
    for(int i=0;i<sz;i++){
        if(isAnagram(lst[i],rs,n)){
            return rs;
        }
    }
    return 0;
}
int main(){
    int n;
    sieve(10000000);
    while(scanf("%d",&n)==1 && n){
        int Prm;
        string a= to_string(n);
        int z= a.size();
        a="";
        for(int i=1;i<=z;i++)
            a+='9';
        int rng= atoi(a.c_str());
        vector<int> lst(upper_bound(P.begin(),P.end(),n),upper_bound(P.begin(),P.end(),rng));
        Prm= chkAnagram(lst,n);
        printf("%d\n",Prm);
    }
}
