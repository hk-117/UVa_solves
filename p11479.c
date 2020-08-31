#include<stdio.h>
int main(){
    long long a,b,c;
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&a,&b,&c);
        printf("Case %d: ",++tc);
        if(a+b<=c || b+c<=a || c+a<=b || a<=0|| b<=0 || c<=0){
            puts("Invalid");
        }
        else{
            if(a==b && b==c){
                puts("Equilateral");
            }
            else if(a!=b && b!=c && c!=a){
                puts("Scalene");
            }
            else{
                puts("Isosceles");
            }
        }
    }
}
