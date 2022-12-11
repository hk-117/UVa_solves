#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n,n){
        multiset<int,greater<int>> bills;
        long long int total=0;
        while(n--){
            int purchase,dbill;
            cin>>purchase;
            while(purchase--){
                cin>>dbill;
                bills.insert(dbill);
            }
            total+= *bills.begin() - *(--bills.end());
            bills.erase(bills.begin());
            bills.erase(--bills.end());
        }
        cout<<total<<endl;
    }
}
