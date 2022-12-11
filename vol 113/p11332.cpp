#include<bits/stdc++.h>
using namespace std;
long int sumdigit(long int number){
    long int total=0;
    while(number>0){
        int digit=number%10;
        total=total+digit;
        number/=10;
    }
    if((total/10)==0)
        return total;
    else
        return sumdigit(total);
}
int main(){
    long int n;
    while(cin>>n){
        if(n==0)
            break;
        cout<<sumdigit(n)<<"\n";
    }
}
