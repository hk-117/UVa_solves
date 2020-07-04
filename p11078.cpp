#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
#define scan(a) scanf("%d",&a)
#define inf 10000000
using namespace std;
int main(){
    int tc;
    scan(tc);
    while(tc--){
        int n;
        scan(n);
        int score,mx=-inf,m=-inf;
        R(i,0,n,1){
            scan(score);
            mx= max(mx, m-score);
            m= max(m,score);
        }
        printf("%d\n",mx);
    }
}
