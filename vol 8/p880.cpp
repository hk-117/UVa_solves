#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    long long basek,k,n,dist;
    while(scanf("%lld",&k)==1){
        n= (-1+(long long)sqrt(1+8*k))/2;
        basek= (n*(n+1))/2;
        dist=k-basek;
        if(dist==0)
            printf("%d/%lld\n",1,n);
        else{
            dist--;
            printf("%lld/%lld\n",n+1-dist,1+dist);
        }
    }
}
