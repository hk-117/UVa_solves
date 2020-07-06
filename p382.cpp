#include<bits/stdc++.h>
#define scan(a) scanf("%d",&a)
using namespace std;
int retRes(int n){
    int su=0;
    for(int i=1;i<n;i++){
        if(n%i==0)
            su+=i;
    }
    return su;
}
int main(){
    int n;
    puts("PERFECTION OUTPUT");
    while(scan(n)==1 && n){
        int res= retRes(n);
        if(res==n){
            printf("%5d  %s\n",n,"PERFECT");
        }
        else if(res>n){
            printf("%5d  %s\n",n,"ABUNDANT");
        }
        else{
            printf("%5d  %s\n",n,"DEFICIENT");
        }
    }
    puts("END OF OUTPUT");
}
