#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;
int iter;
bool isPalindrome(string st){
    int n=st.size();
    R(i,0,n/2+1,1){
        if(st[i]!=st[n-1-i])
            return false;
    }
    return true;
}
long long findPalindrome(string rev){
    iter++;
    string num=rev;
    reverse(rev.begin(),rev.end());
    long long a= atol(num.c_str());
    long long b= atol(rev.c_str());
    long long ans=a+b;
    if(isPalindrome(to_string(ans))){
        return ans;
    }
    else
        return findPalindrome(to_string(ans));
}
int main(){
    int n;
    cin>>n;
    while(n--){
        string num;
        cin>>num;
        long long ans= findPalindrome(num);
        cout<<iter<<" "<<ans<<endl;
        iter=0;
    }
}
