#include<cstdio>
#include<cmath>
#define eps 1e-9
using namespace std;
int main(){
    double x;
    int n,L;
    while(scanf("%d",&n)==1 && n){
        x=-5;
        L=0;
        while(fabs(x)+eps>1){
            x = 1 - (n / exp(L));
            L++;
        }
        L--;
        printf("%d %.8lf\n",L,x);
    }
}
