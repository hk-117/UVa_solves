#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    
    while(t--){
        long int num;
        scanf("%ld",&num);
        num*=567;
        num/=9;
        num+=7492;
        num*=235;
        num/=47;
        num-=498;
        num/=10;
        printf("%ld\n",abs(num%10));
    }
}
