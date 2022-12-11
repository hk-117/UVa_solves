#include <cstdio>
#include <cstring>
using namespace std;
long long N = 5, V, coinValue[5] = {1, 5, 10, 25, 50}, memo[6][35000];
long long ways(long long type, long long value) {
    if (value == 0) return 1;
    if (value < 0 || type == N)  return 0;
    if (memo[type][value] != -1) return memo[type][value];
    memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
    return memo[type][value];
}
int main() {
    memset(memo, -1, sizeof memo);
    while (scanf("%lld", &V)==1){
        long long ans=ways(0,V);
        if(ans==1)
            printf("There is only 1 way to produce %lld cents change.\n",V);
        else
            printf("There are %lld ways to produce %lld cents change.\n",ans,V);
    }
}
