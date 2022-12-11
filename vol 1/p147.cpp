#include<bits/stdc++.h>
using namespace std;
long long N=11,V,coinValue[11]={5,10,20,50,100,200,500,1000,2000,5000,10000}, memo[15][100005];
long long ways(long long type, long long value) {
    if (value == 0) return 1;
    if (value < 0 || type == N)  return 0;
    if (memo[type][value] != -1) return memo[type][value];
    memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
    return memo[type][value];
}
int main(){
    string nm;
    double v;
    memset(memo, -1, sizeof memo);
    while (cin>>nm, atof(nm.c_str())){
        string a(nm.begin(),nm.begin()+nm.find(".")),b(nm.begin()+nm.find(".")+1,nm.end());
        long long m= atoi(a.c_str())*100,n=atoi(b.c_str());
        V=m+n;
        v=atof(nm.c_str());
        printf("%6.2lf%17lld\n",v,ways(0,V));
    }
}
