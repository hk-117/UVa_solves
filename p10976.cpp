#include<bits/stdc++.h>
#define scan(a) scanf("%d",&a)
#define R(i,a,b,c) for(long long i=a;i<=b;i+=c)
using namespace std;
int main(){
    int k;
    while(scan(k)==1){
        vector<pair<long long,long long>> sol;
        R(i,k+1,2*k,1){
            long long y=i;
            long long x=(long long) (k*y)/(y-k);
            if(((x*y)/(x+y)) == k){
                sol.push_back(make_pair(x,y));
            }
        }
        printf("%ld\n",sol.size());
        for(auto it=sol.begin();it!=sol.end();it++){
            printf("1/%d = 1/%lld + 1/%lld\n",k,it->first,it->second);
        }
    }
}
