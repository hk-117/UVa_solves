#include<bits/stdc++.h>
using namespace std;
int digitSum(int num){
    int d,s=0;
    while(num){
        d=num%10;
        num/=10;
        s+=d;
    }
    return s;
}
int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int C[4];
        for(int i=0;i<4;i++){
            scanf("%d",&C[i]);
        }
        int tot=0;
        for(int i=0;i<4;i++){
            int nm=C[i];
            bool d=false;
            while(nm){
                int dig=nm%10;
                nm=nm/10;
                if(d){
                    tot+= digitSum(2*dig);
                    d=false;
                }
                else{
                    tot += dig;
                    d=true;
                }
            }
        }
        if(tot%10==0)
            puts("Valid");
        else
            puts("Invalid");
    }
}
