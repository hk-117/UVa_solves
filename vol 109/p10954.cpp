#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int main(){
    int n;
    while(cin>>n,n){
        priority_queue<long long> numbers;
        long long num;
        R(i,0,n,1){
            cin>>num;
            numbers.push(-num);
        }
        long long a1,a2,cost=0;
        while(numbers.size() != 1){
            a1=numbers.top();
            numbers.pop();
            a2=numbers.top();
            numbers.pop();
            cost+= (-(a1+a2));
            numbers.push(a1+a2);
        }
        cout<< cost <<endl;
    }
}
