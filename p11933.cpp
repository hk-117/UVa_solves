#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int num;
    while(scanf("%d",&num),num){
        int a=0,b=0;
        int t=num& (-num);
        int pos=1;
        while(t){
            if(pos%2==1){
                a|=t;
            }
            else{
                b|=t;
            }
            num&=(num-1);
            t=num &(-num);
            pos++;
        }
        cout<<a<<" "<<b<<endl;
    }
}
