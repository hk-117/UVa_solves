#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)

using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> num(n);
        R(i,0,n,1)
            cin>>num[i];
        sort(num.begin(),num.end());
        int a= num[(n-1)/2];
        int md,possible,cnt=0,st;
        st=(n-1)/2;
        if(n%2)
            md= st;
        else
            md=st+1;
        possible= num[md] -a +1;
        R(i,0,n,1){
            if(num[i]>=num[st] && num[i]<=num[md])
                cnt++;
            if(num[i]>num[md])
                break;
        }
        cout<<a<<" "<<cnt<<" "<<possible<<endl;

    }
}
