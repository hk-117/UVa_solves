#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
}lft,rgt,I;
int n,m;
void BS(){
    if(!(I.a==n && I.b==m)){
        if(I.a*m < I.b*n){
            putchar('R');
            lft=I;
            I.a=I.a+rgt.a;
            I.b=I.b+rgt.b;
            BS();
        }
        else{
            putchar('L');
            rgt=I;
            I.a=I.a+lft.a;
            I.b=I.b+lft.b;
            BS();
        }
    }
    else{
        puts("");
    }
}
int main(){
    while(cin>>n>>m,!(n==1 && m==1)){
        lft.a=0;
        lft.b=1;
        rgt.a=1;
        rgt.b=0;
        I.a=1;
        I.b=1;
        BS();
    }
}
