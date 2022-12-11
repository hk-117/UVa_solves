#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int T;
    cin>>T;
    while(T--){
        string S;
        ll N,sz;
        stack<ll> F;
        deque<char> L;
        cin>>S>>N;
        sort(S.begin(),S.end());
        sz=S.size();
        for(int i=1;i<=sz;i++){
            F.push(N%i);
            N/=i;
        }
        L.assign(S.begin(),S.end());
        while(F.size()){
            cout<< L[F.top()];
            L.erase(L.begin()+F.top());
            F.pop();
        }
        cout<<"\n";
    }
}
