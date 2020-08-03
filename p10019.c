#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Ones[]={0,1,1,2,1,2,2,3,1,2};
int cntOnes(int m){
    int cnt=0;
    while(m){
        if(m%2){
            cnt++;
        }
        m/=2;
    }
    return cnt;
}
int cntHexOnes(int m){
    int digit,cnt=0;
    while(m){
        digit= m%10;
        cnt+= Ones[digit];
        m/=10;
    }
    return cnt;
}
int main(){
    int n,m;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d",&m);
        a= cntOnes(m);
        b= cntHexOnes(m);
        printf("%d %d\n",a,b);
    }
}
