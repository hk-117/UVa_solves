#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int squares[10000];
    R(i,0,10000,1){
        squares[i]= i*i;
    }
    int bits;
    while(cin>>bits){
        int brk= (int)pow(10,bits),f,s;
        R(i,0,10000,1){
            if(squares[i]>=brk)
                break;
            f= squares[i]/(int)(pow(10,bits/2));
            s= squares[i]%(int)(pow(10,bits/2));
            if(pow(f+s,2)==squares[i]){
                printf("%0*d\n",bits,squares[i]);
            }
        }
    }
}
