#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    long long a,b;
    while(cin>>a>>b,a||b){
        string num1=to_string(a),num2=to_string(b);
        int carry=0,prevcarry=0;
        int len1=num1.size(),len2=num2.size();
        int lop= max(len1,len2);
        int dig1,dig2;
        R(i,1,lop+1,1){
            if(len2-i <0)
                dig2=0;
            else
                dig2=num2[len2-i]-'0';
            if(len1-i <0)
                dig1=0;
            else
                dig1=num1[len1-i]-'0';
            int sum=dig1+dig2+prevcarry;
            prevcarry=0;
            if(sum>9){
                carry++;
                prevcarry=sum/10;
            }
        }
        if(!carry)
            puts("No carry operation.");
        else{
            if(carry==1)
                printf("%d carry operation.\n",carry);
            else
                printf("%d carry operations.\n",carry);
        }
    }
}
