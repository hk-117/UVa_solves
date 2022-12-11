#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,tc=0;
    while(cin>>n,n){
        int sol=0,b,a;
        if(tc)
            puts("");
        tc++;
        for(b=1234;b<=98765/n;b++){
            a= b*n;
            int tmp=b;
            int marker = (b<10000);
            while(tmp){
                marker |= 1<<(tmp%10);
                tmp/=10;
            }
            tmp=a;
            while(tmp){
                marker |= 1<<(tmp%10);
                tmp/=10;
            }
            if(marker == (1<<10)-1){
                printf("%05d / %05d = %d\n",a,b,n);
                sol++;
            }
        }
        if(!sol){
            printf("There are no solutions for %d.\n",n);
        }
    }
}
