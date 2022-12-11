#include <cstdio>
#include <cstring>
using namespace std;
long long N = 21, V, coinValue[21] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261}, memo[22][15000];
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
        printf("%lld\n",ways(0,V));
    }
}
