#include<bits/stdc++.h>
#define R(i,a,b,c) for(int i=a;i<b;i+=c)
using namespace std;

int main(){
    int k;
    cin>>k;
    cin.ignore();
    while(k--){
        int m,n,num;
        string a,u;
        cin>>m>>n;
        vector<long long int> goes,fu;
        R(i,0,m,1){
            cin>>num;
            goes.push_back(num);
        }
        R(i,0,n,1){
            cin>>num;
            fu.push_back(num);
        }
        cin.ignore();
        multiset<long long int> au;
        au.insert(goes[0]);
        auto it=au.begin();
        R(i,1,m,1){
            while(au.size()== *fu.begin() && fu.size()){
                cout<< *it <<endl;
                it++;
                fu.erase(fu.begin());
            }
            au.insert(goes[i]);
            if(it==au.end() || *it > goes[i])
                it--;
        }
        while(au.size()== *fu.begin() && fu.size()){
            cout<< *it <<endl;
            it++;
            fu.erase(fu.begin());
        }
        if(k)
            cout<<endl;
    }
}
